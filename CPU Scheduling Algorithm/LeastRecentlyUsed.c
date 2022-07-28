#include <stdio.h>
int main()
{
    int counter = 0, flag1, flag2, i, j, pos, faults = 0;
    int pno;
    printf("Enter number of pages: ");
    scanf("%d", &pno);
    int pages[pno];
    printf("Enter page values: ");
    for (i = 0; i < pno; ++i)
    {
        scanf("%d", &pages[i]);
    }
    int fno;
    printf("Enter number of frames: ");
    scanf("%d", &fno);
    int frames[fno];
    int time[fno];
    for (i = 0; i < fno; ++i)
    {
        frames[i] = -1;
    }
    int pagehit = 0;

    for (i = 0; i < pno; ++i)
    {
        flag1 = flag2 = 0;
        for (j = 0; j < fno; ++j)
        {
            if (frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                pagehit++;
                break;
            }
        }

        if (flag1 == 0)
        {
            for (j = 0; j < fno; ++j)
            {
                if (frames[j] == -1)
                {
                    counter++;
                    faults++;
                    frames[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            pos = findLRU(time, fno);
            counter++;
            faults++;
            frames[pos] = pages[i];
            time[pos] = counter;
        }
        printf("\n");
        for (j = 0; j < fno; ++j)
        {
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);
    printf("\n%d", pagehit);
    return 0;
}
int findLRU(int time[], int n)
{
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i)
    {
        if (time[i] < minimum)
        {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}