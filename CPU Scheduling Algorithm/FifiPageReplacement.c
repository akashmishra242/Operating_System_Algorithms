#include <stdio.h>
int main()
{
    int i, j, k, avail,
    ;
    int pn;
    printf("\n ENTER THE NUMBER OF PAGES:\n");
    scanf("%d", &pn);
    int pagen[np];
    printf("\n ENTER THE PAGE NUMBER :\n");
    for (i = 1; i <= n; i++)
        scanf("%d", &pagen[i]);
    int fn;
    printf("\n ENTER THE NUMBER OF FRAMES :");
    scanf("%d", &fn);
    int frame[fn];
    for (i = 0; i < no; i++)
        frame[i] = -1;
    j = 0;
    int avail;
    printf("\tref string\t page frames\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d\t\t", a[i]);
        avail = 0;
        for (k = 0; k < no; k++)
            if (frame[k] == a[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = a[i];
            j = (j + 1) % no;
            count++;
            for (k = 0; k < no; k++)
                printf("%d\t", frame[k]);
        }
        printf("\n");
    }
    printf("Page Fault Is %d", count);
    return 0;
}