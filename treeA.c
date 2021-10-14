#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void insert(int *a, int ele)
{
    int i = 0;
    while (i < MAX && a[i] != 0)
    {
        if (ele < a[i])
        {
            i = 2 * i + 1;
        }
        else
        {
            i = 2 * 1 + 2;
        }
    }
    a[i] = ele;
}

void inorder(int *a, int i)
{
    if (a[0] == 0)
    {
        return;
    }
    inorder(a, (i * 2) + 1);
    printf("%d\t", a[i]);
    inorder(a, (i * 2) + 2);
}

void postorder(int *a, int i)
{
    if (a[0] == 0)
    {
        return;
    }
    else
    {
        postorder(a, (i * 2) + 2);
        postorder(a, (i * 2) + 1);
        printf("%d\t", a[i]);
    }
}

int isEqual(int *a, int *b)
{
    for (int i = 0; i < MAX; i++)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        else
        {
            return 0;
            break;
        }
    }
    return 1;
}

int main()
{
    int a[MAX], b[MAX];
    int ele, choice, x;
    for (int i = 0; i < MAX; i++)
    {
        a[i] = 0;
    }
    for (;;)
    {
        printf("1 insert 2 inorder 3 preoder 4 postorder\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nenter ele\n");
            scanf("%d", &ele);
            insert(a, ele);
            break;
        case 2:
            if (a[0] == 0)
                printf("\nempty\n");
            inorder(a, 0);
            break;
        case 3:
            printf("\nenter ele\n");
            scanf("%d", &ele);
            insert(b, ele);
            break;
        case 4:
            x = isEqual(a, b);
            if (x)
            {
                printf("is equal\n");
            }
            else
            {
                printf("not equal\n");
            }
        default:
            break;
        }
    }
}