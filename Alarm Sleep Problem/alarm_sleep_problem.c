#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

int main()
{ if (fork() != 0)
{
alarm(8);
printf("I am the parent \n");
sleep(3);
while(1){
    printf("202011006\n");
}
}
else while (1)
{
alarm(6);
printf("I am the child \n");
sleep(2);
}
}