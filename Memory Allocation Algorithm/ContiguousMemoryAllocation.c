#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void recurse(int files[], int n)
{
    int flag = 0, startBlock, len, j, k, ch;
    printf("Enter the starting block ");
    scanf("%d", &startBlock);
    printf("Enter the length of the files: ");
    scanf("%d", &len);
    for (j = startBlock; j < (startBlock + len); j++)
    {
        if (files[j] == 1)
            flag++;
    }
    if (len == flag)
    {
        for (int k = startBlock; k < (startBlock + len); k++)
        {
            if (files[k] == 1)
            {
                files[k] = 0;
                printf("%d\t%d\n", k, files[k]);
            }
        }
        if (k != (startBlock + len - 1))
            printf("The file is allocated to the disk\n");
    }
    else
        printf("The file is not allocated to the disk\n");

    printf("Do you want to enter more files?\n");
    printf("Press 1 for YES, 2 for NO: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse(files, n);
    else
    {
        printf("Availible files are \n");
        for (int i = 0; i < n; i++)
        {
            if (files[i] == 1)
            {
                printf("%d\t%d\n", i, files[i]);
            }
        }
        exit(0);
    }
    return;
}

int main()
{
    printf("Enter the number of files \n");
    int n;
    scanf("%d", &n);
    int files[n];
    for (int i = 0; i < n; i++)
        files[i] = 1;
    recurse(files, n);
    getch();
    return 0;
}