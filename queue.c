#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct que
{
    int front;
    int rear;
    int size;
    int *array;
};
typedef struct que que;

que *create(int size)
{
    que *q;
    // typecasting not mandatory as malloc returns a general pointer
    q = (que *)malloc(sizeof(que));
    q->front = -1;
    // not arrow as q is a pointer
    q->size = size;
    q->rear = -1;
    q->array = (int *)malloc(size * sizeof(int));
    return (q);
}

int isfull(que *q)
{
    return (q->rear == q->size);
}

int isEmpty(que *q)
{
    return (q->front >= q->rear);
}

void enque(que *q, int ele)
{
    if (isfull(q))
    {
        return;
    }
    else
    {
        ++(q->rear);
        q->array[q->rear] = ele;
    }
}

void display(que *q)
{
    if (isEmpty(q))
    {
        return;
    }
    else
    {
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d\t", q->array[i]);
        }
    }
}

int deque(que *q)
{
    if (isEmpty)
    {
        return (-999);
    }
    else
    {
        ++(q->front);
        int x = q->array[q->front];
        return (x);
    }
}

int main()
{
    que *q = create(5);
    int ele;
    int choice;
    int x : while (1)
    {
        printf("1:enque\t2:deque\t3:display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter ele\n");
            scanf("%d", &ele);
            enque(q, ele);
            break;
        case 2:
            int x = deque(q);
            if (x = -999)
            {
                printf("empty que\n")
            }
            else
            {
                printf("delete successful\n");
            }

        case 3:
            display(q);

        default:
            break;
        }
    }
}