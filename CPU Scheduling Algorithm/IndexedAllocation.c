#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int files[50], indexBlock[50], indBlock, n;
void recurse1();
void recurse1()
{
    printf("Enter the index block: ");
    scanf("%d", &indBlock);
    if (files[indBlock] != 0)
    {
        printf("Enter the number of blocks and the number of files needed for the index %d on the disk: ", indBlock);
        scanf("%d", &n);
    }
    else
    {
        printf("%d is already allocated\n", indBlock);
        recurse1();
    }
    recurse2();
}

void recurse2()
{
    int ch;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &indexBlock[i]);
        if (files[indexBlock[i]] == 0)
            flag++;
    }
    if (flag == n)
    {
        for (int j = 0; j < n; j++)
        {
            files[indexBlock[j]] = 1;
        }
        printf("Allocated\n");
        printf("File Indexed\n");
        for (int k = 0; k < n; k++)
        {
            printf("%d ------> %d : %d\n", indBlock, indexBlock[k], files[indexBlock[k]]);
        }
    }
    else
    {
        printf("File in the index is already allocated\n");
        printf("Enter another indexed file\n");
        recurse2();
    }
    printf("Do you want to enter more files?\n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse1();
    else{
        printf("Availible files are \n");
    for (int i = 0; i < n; i++)
    {
        if (files[i] == 1)
        {
            printf("%d\t%d\n", i, files[i]);
        }
    }
    exit(0);}
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

    recurse1();
    return 0;
}