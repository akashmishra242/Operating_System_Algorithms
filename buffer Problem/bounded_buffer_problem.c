#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 7

sem_t empty;
sem_t full;
int buffer[BUFFER_SIZE];
pthread_mutex_t mutex;
void *Producer();
void *Consumer();
int in = 0;
int out = 0;

int main()
{
    pthread_t p,c;
    pthread_mutex_init(&mutex , NULL);
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    
    pthread_create(&p,NULL,(void *)Producer,NULL);
    pthread_create(&c,NULL,(void *)Consumer,NULL);
    pthread_join(p,NULL);
    pthread_join(c,NULL);
    
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
}

void *Producer(){
    
   for(int i =0;i<BUFFER_SIZE;i++){
       sem_wait(&empty);
       pthread_mutex_lock(&mutex);
       int value=rand()%100;
       buffer[in]=value;
       printf("The value inserted in buffer at %d by producer is :  %d\n",(in+1),value);
       in = (in+1) % BUFFER_SIZE;
       pthread_mutex_unlock(&mutex);
       sem_post(&full);
   } 
}

void *Consumer(){
    
    for(int i = 0;i<BUFFER_SIZE;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("The value deleted in buffer at %d by Consumer is :  %d\n",(out+1),buffer[out]);
        out=(out+1)%BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    
    
}






