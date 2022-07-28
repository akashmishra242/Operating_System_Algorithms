#include<unistd.h>
#include<stdbool.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>

#define MAX_ITEMS 7
#define BUFFER_SIZE 7

void *producer(void *ID);
void *consumer(void *ID);


sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BUFFER_SIZE];
pthread_mutex_t mutex;

int main()
{   

    srand(time(NULL));
    int n = rand()%5;

    int IDs[n];

    pthread_t p[n], c[n];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    for(int i = 0; i < n; i++) {
        pthread_create(&p[i], NULL, (void *)producer, (void *)&IDs[i]);
    }
    for(int i = 0; i < n; i++) {
        pthread_create(&c[i], NULL, (void *)consumer, (void *)&IDs[i]);
    }

    for(int i = 0; i < n; i++) {
        pthread_join(p[i], NULL);
    }
    for(int i = 0; i < n; i++) {
        pthread_join(c[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
    
}

void *producer(void *ID)
{   
    int item;
    for(int i = 0; i < MAX_ITEMS; i++) {
        item = rand()%10001; 
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)ID), item, in);
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
}
void *consumer(void *ID)
{   
    for(int i = 0; i < MAX_ITEMS; i++) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        int item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)ID), item, out);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
}