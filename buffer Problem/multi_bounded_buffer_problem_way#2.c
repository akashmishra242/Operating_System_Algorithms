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
void *Producer(int* whichP);
void *Consumer(int* whichC);
int in = 0;
int out = 0;

int main()
{
    
    pthread_mutex_init(&mutex , NULL);
    sem_init(&empty,0,BUFFER_SIZE);
    sem_init(&full,0,0);
    int random = rand()%5;
    printf("The value of multiple producer consumer problem selected is %d :\n\n",random);
    pthread_t p[random],c[random];
    int PC_ID[random];
   
    for(int i=0;i<random;i++)
    {
        PC_ID[i]=i+1;
       pthread_create(&p[i],NULL,(void *)Producer,(int *)&PC_ID[i]);
       sleep(1); 
       //applied sleep so that it can switch to next line //and to avoid deadlock condition
        pthread_create(&c[i],NULL,(void *)Consumer,(int *)&PC_ID[i]);
        sleep(1);
        pthread_join(p[i],NULL);
        sleep(1);
        pthread_join(c[i],NULL);
    }
   
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
    
}

void *Producer(int* whichP){
    
   for(int i =0;i<BUFFER_SIZE;i++){
       sem_wait(&empty);
       pthread_mutex_lock(&mutex);
       int value=rand()%100;
       buffer[in]=value;
       printf("The value inserted in buffer_id#%d at %d by producer is :  %d\n",*whichP,(in+1),value);
       in = (in+1) % BUFFER_SIZE;
       pthread_mutex_unlock(&mutex);
       sem_post(&full);
   } 
}

void *Consumer(int* whichC){
    
    for(int i = 0;i<BUFFER_SIZE;i++){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        printf("The value deleted in bufferr_id#%d at %d by Consumer is :  %d\n",*whichC,(out+1),buffer[out]);
        out=(out+1)%BUFFER_SIZE;
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }
    
    
}







