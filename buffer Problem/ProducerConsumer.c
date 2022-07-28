#include <stdio.h>
#include <stdlib.h>
int count = 0;
int front = 0;
int rear = 0;
char buffer[5];
int prodsleep = 0;
int consleep = 0;
void producer(void)
{
    char item;
    if (count < 5)
    {
        printf("\n Enter charecter data:");
        scanf(" %c", &item);
        buffer[front] = item;
        front = (front + 1) % 5;
        count++;
        if (consleep == 1 && count == 1)
        {
            printf("\n Consumer Wakeup ");
        }
    }
    else
    {
        printf("\n Sorry!! Buffer if full");
        prodsleep = 1;
    }
}
void consumer(void)
{
    char item;
    if (count > 0)
    {
        item = buffer[rear];
        buffer[rear] = ' ';
        printf("\n Consumed item: %c", item);
        rear = (rear + 1) % 5;
        count--;
        if (prodsleep == 1 && count == 4)
        {
            printf("\n Producer Wakeup");
        }
    }
    else
    {
        printf("\n Sorry!! Buffer is Empty");
        consleep = 1;
    }
}
void view(void)
{
    int i;
    printf("\n Buffer Data : ");
    printf("\n +----------------------+\n");
    for (i = 0; i < 5; i++)
    {
        printf("| %c ", buffer[i]);
    }
    printf("| \n +-------------------------+");
}
int main()
{
    int i, choice, flag = 0;
    printf("\n 1:Insert item using producer ");
    printf("\n 2:Remove item using consumer ");
    printf("\n 3:View buffer data ");
    printf("\n 4:Exit ");

    do
    {
        printf("\n\n Enter your choice :");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            view();
            break;
        case 4:
            flag = 1;
            break;
        default:
            printf("\n Please enter correct choice!");
            break;
        }
    } while (flag == 0);
}
