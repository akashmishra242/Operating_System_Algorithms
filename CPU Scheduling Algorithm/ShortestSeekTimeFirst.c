#include<stdio.h>
 
struct head
{
      int num;
      int flag;
};
 
int main()
{
      struct head h[33];
      int array_1[33], array_2[33];
      int count = 0, j, x, limit, minimum, location, disk_head, sum = 0;
      printf("\nEnter total number of locations:\t");
      scanf("%d", &limit);
      printf("\nEnter position of disk head:\t");
      scanf("%d", &disk_head);
      printf("\nEnter elements of disk head queue\n");
      for(count = 0;count<limit;count++)
      {
            scanf("%d", &h[count].num);   
            h[count].flag = 0;
            }
      for(count = 0; count < limit; count++)
      {                 
            x = 0; 
            minimum = 0;
            location = 0;
            for(j = 0; j < limit; j++)
            {
                  if(h[j].flag == 0)
                  {
                        if(x == 0)
                        {
                              array_1[j] = disk_head - h[j].num;
                              if(array_1[j] < 0)
                              { 
                                    array_1[j] = h[j].num - disk_head;
                              }
                              minimum = array_1[j];
                              location = j;
                              x++; 
                        }
                        else
                        {
                              array_1[j] = disk_head - h[j].num;
                              if(array_1[j] < 0)
                              { 
                                    array_1[j] = h[j].num - disk_head;
                              }
                        }
                        if(minimum > array_1[j])
                        { 
                              minimum = array_1[j]; 
                              location = j;
                        }
                  }
            }
            h[location].flag = 1;
            array_2[count] = h[location].num - disk_head;
            if(array_2[count] < 0)
            {
                  array_2[count] = disk_head - h[location].num;
            }
            disk_head = h[location].num;
      }
      count = 0;
      for(count=0;count<limit;count++)
      {
            sum = sum + array_2[count];      
      }
      printf("\nTotal movements of the cylinders:\t%d", sum);
      return 0;
}