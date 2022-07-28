// Banker's Algorithm
#include <stdio.h>
int main()
{
	// P0, P1, P2, P3, P4 are the Process names here

	int n, m, i, j, k;
    printf("\nEnter number of processes: ");
     scanf("%d", &n);
     printf("\nEnter max resource: ");
     scanf("%d", &m);
	int alloc[n];
    int sum=0
     for (int i = 0; i < n; i++)
        {
            scanf("%d", &alloc[i]);
            sum=sum+alloc[i];
        }
        
        int max[n];
     for (int i = 0; i < n; i++)
        {
            scanf("%d", &max[i]);
        } // P4

	int avail= m-sum;// Available Resources
printf("%d",&avail);
int 
for(int i=0;i<n;i++){
    if()
}
	int f[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		f[k] = 0;
	}
	int need[n];
	for (i = 0; i < n; i++) {
		need[i] = max[i] - alloc[i];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (f[i] == 0) {

				int flag = 0;
				if (need[i] > avail){
					{	flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i;
					for (y = 0; y < m; y++)
						avail += alloc[i];
					f[i] = 1;
				}
			}
		}
	}

	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d", ans[n - 1]);

	return (0);

	// This code is contributed by Deep Baldha (CandyZack)
}
