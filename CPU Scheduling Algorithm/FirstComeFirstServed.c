#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number of process ");
    scanf("%d",&n);
    int process[n];
    printf("Enter the processes ");
	 for(int i=0;i<n;i++){
        scanf("%d",&process[i]);
    }
    printf("\nEnter position of disk head:\t");
    int dhead;
    scanf("%d",&dhead);
    int seek_count = 0;
	int distance, cur_track;

	for (int i = 0; i < size; i++)
	{
		cur_track = process[i];

		// calculate absolute distance
		distance = Math.abs(cur_track - head);

		// increase the total count
		seek_count += distance;

		// accessed track is now new head
		head = cur_track;
	}
    printf("Total number of seek operations = %d",seek_count);
    printf("Seek Sequence is");
	for (int i = 0; i < size; i++)
	{
		printf(process[i]);
	}
return 0;
}