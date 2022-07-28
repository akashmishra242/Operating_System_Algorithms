#include<stdio.h>
void main()
{
	int b_num, p_num, i, j;
	printf("Enter no. of blocks: ");
	scanf("%d", &b_num);
	int bsize[b_num];
	printf("\nEnter size of each block: ");
	for(i = 0; i < b_num; i++){
	scanf("%d", &bsize[i]);
	}
	printf("\nEnter no. of processes: ");
	scanf("%d", &p_num);
	int psize[p_num];
	printf("\nEnter size of each process: ");
	for(i = 0; i < p_num; i++)
		scanf("%d", &psize[i]);
	int flags[b_num],allocation[p_num];
	for(i = 0; i < b_num; i++)
	{
		 flags[i] = 0;
	}
	for(i=0;i<p_num;i++){
	    allocation[i]=-1;
	}
    j=0;
	int count=0;
	for(i = 0; i < p_num; i++){     //allocation as per first fit
		while(j < b_num){
			if(count == 2*b_num){
				break;
			}
			else{
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
                allocation[j] = i;
				flags[j] = 1;
				break;
			}
            j=((j+1)%b_num);
			count++;
        }}}
	//display allocation details
	int diff=0;
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < b_num; i++)
	{
		printf("\n%d\t\t%d\t\t", i+1, bsize[i]);
		if(flags[i] == 1){
			printf("%d\t\t\t%d",allocation[i]+1,psize[allocation[i]]);
			diff=diff+(bsize[i]-psize[allocation[i]]);
		}
		else
			printf("Not allocated");
	}
    printf("\nSize of memory wasted: ");
	printf("%d",diff);
}