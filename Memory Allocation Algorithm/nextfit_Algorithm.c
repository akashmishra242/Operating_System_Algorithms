#include<stdio.h>
void main()
{
	int bno, pno, i, j;
	printf("Enter no. of blocks: ");
	scanf("%d", &bno);
	int bsize[bno];
	printf("\nEnter size of each block: ");
	for(i = 0; i < bno; i++){
	scanf("%d", &bsize[i]);
	}
	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	int psize[pno];
	printf("\nEnter size of each process: ");
	for(i = 0; i < pno; i++)
		scanf("%d", &psize[i]);
	int flags[bno],allocation[pno];
	for(i = 0; i < bno; i++)
	{
		 flags[i] = 0;
	}
	for(i=0;i<pno;i++){
	    allocation[i]=-1;
	}
    j=0;
	int count=0;
	for(i = 0; i < pno; i++){     //allocation as per first fit
		while(j < bno){
			if(count == 2*bno){
				break;
			}
			else{
			if(flags[j] == 0 && bsize[j] >= psize[i])
			{
                allocation[j] = i;
				flags[j] = 1;
				break;
			}
            j=((j+1)%bno);
			count++;
        }}}
	//display allocation details
	int diff=0;
	printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
	for(i = 0; i < bno; i++)
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