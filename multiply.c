#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **ptr1, **ptr2, **ptr3;
    int r1, r2, col1, col2;
    int i, j, k;
    printf("enter the no of rows\n");
    scanf("%d", &r1);
    printf("enter the no of rows\n");
    scanf("%d", &r2);
    printf("enter the no of cols\n");
    scanf("%d", &col1);
    printf("enter the no of rows\n");
    scanf("%d", &col2);
    if (!(col1 != r2))
    {
        ptr1 = (int **)malloc(sizeof(int *) * r1);
        ptr2 = (int **)malloc(sizeof(int *) * r2);
        ptr3 = (int **)malloc(sizeof(int *) * r1);
        for (int i = 0; i < r1; i++)
        {
            ptr1[i] = (int *)malloc(sizeof(int) * col1);
        }
        for (int i = 0; i < r2; i++)
        {
            ptr2[i] = (int *)malloc(sizeof(int) * col2);
        }
        for (int i = 0; i < r1; i++)
        {
            ptr3[i] = (int *)malloc(sizeof(int) * col2);
        }
        printf("m1\n");
        for (int i = 0; i < r1; i++)
        {
            for (int i = 0; i < col1; i++)
            {
                scanf("%d", &ptr1[i][j]);
            }
        }
        printf("m2\n");
        for (int i = 0; i < r2; i++)
        {
            for (int i = 0; i < col2; i++)
            {
                scanf("%d", &ptr2[i][j]);
            }
        }
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                ptr3[i][j]=0;
                for (int k = 0; k < r2; k++)
                {
                    ptr3[i][j]+=ptr1[i][k]*ptr2[k][j];
                }
                
            }
            
        }
        // matrix mul=sigma(a[i][k]*b[k][j])
        
    }
    else
    {
        printf(":-(");
    }
}