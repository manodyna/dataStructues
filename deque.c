#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct deque
{
    int *array;
    int rear;
    int front;
    int size;
} que;

void init(que *q)
{
    q->array = (int *)malloc((q->size) * sizeof(int));
    q->rear = q->front = -1;
}

void insertRear(que *q, int ele)
{
    if (q->front == 0 && q->rear == q->size - 1 || q->front == q->rear + 1)
    {
        return;
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
            q->rear = 0;
        }
        else if (q->rear - q->size - 1)
        {
            q->rear = 0;
        }
        else
        {
            (q->rear)++;
        }
    }
    q->array[q->rear] = ele;
    //  ++(q->rear);
}

void insertFront(que *q, int ele)
{
    if (q->front == 0 && q->rear == q->size - 1 || q->front == q->rear + 1)
    {
        return;
    }
    // anticlockwise append
    else
    {
        if (q->front == -1 && q->rear == -1)
        {
            q->front = q->rear = 0;
        }
        else if (q->front == 0)
        {
            q->front == q->size - 1;
        }
        else
        {
            (q->front)--;
        }
    }
    q->array[q->front] = ele;
}

void deleteFront(que *q)
{
    if (q->front == -1)
    {
        return;
    }
    else if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else if (q->front = q->size - 1)
    {
        (q->front) = 0;
    }
    else
    {
        q->front++;
    }
}

void deleteRear(que *q)
{
    if (q->front == -1)
    {
        return;
    }
    else if (q->rear == q->front)
    {
        q->rear = q->front = -1;
    }
    else if (q->rear == 0)
    {
        q->rear == q->size - 1;
    }
    else
    {
        q->rear--;
    }
}