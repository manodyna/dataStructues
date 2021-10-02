#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct
{
    int *array;
    int front;
    int rear;
    int size;
} que;

void init(que *q)
{
    q->front = -1;
    q->rear = -1;
    q->array = malloc(q->size * sizeof(int));
}

int isFull(que *q)
{
    if ((q->front) == (q->rear - 1) || q->rear == q->size - 1 && q->front == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int isEmpty(que *q)
{
    return (q->front == -1);
}

int deque(que *q)
{
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
        return(0);
    }
    else
    {
        if (!isEmpty(q))
        {
            int x = q->front;
            q->front=(q->front + 1) % q->size;
            return (x);
        }
        else
        {
            return (-999);
        }
    }
}

void insert(que *q, int ele)
{
    if (!isFull(q))
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->size;
        q->array[q->rear] = ele;
    }
}

void display(que *q){
    if(!isEmpty(q)){
        for (int i = q->front; i != q->rear; i=(i+1)%(q->size))
        {
            printf("%d\t", (q->array[i]));
        }
        printf("%d\t", q->array[q->rear]);
    }
}

int main()
{
    que q;
    printf("enter the size\n");
    int size;
    scanf("%d", &q.size);
    init(&q);
    int choice;
    int x;
    while (1)
    {
        printf("1:enque\t2:deque\t3:display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter ele\n");
            int ele;
            scanf("%d", &ele);
            insert(&q, ele);
            break;
        case 2:
            int x;
            x= deque(&q);
            if (x == -999)
            {
                printf("empty que\n");
            }
            else
            {
                printf("delete successful\n");
            }
            break;

            case 3:
                display(&q);
                break;

        default:
            break;
        }
    }
}