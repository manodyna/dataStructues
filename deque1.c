#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};

struct deque1
{
    struct node *front;
    struct node *rear;
};

void insertFront(int ele, struct deque1 *p)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->rlink = temp->llink = NULL;
    if (p->front == p->rear && p->rear == NULL)
    {
        p->front = temp;
        p->rear = temp;
    }
    else
    {
        temp->rlink = p->front;
        p->front->llink = temp;
        p->front = temp;
    }
}

void insertRear(int ele, struct deque1 *p)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->rlink = temp->llink = NULL;
    if (p->rear == p->front && p->front == NULL)
    {
        p->rear = temp;
        p->front = temp;
    }
    else
    {
        temp->llink = p->rear;
        p->rear->rlink = temp;
        p->rear = temp;
    }
}

void display(struct deque1 p)
{
    if (p.front == NULL)
    {
        printf("empty queue");
    }
    else
    {
        struct deque *q;
        // for (p=q.front; p!=q.rear ; p=p.rlink)
        // {
        //     /* code */
        // }
    }
}

void deleteFront(struct deque1 *p)
{
    if (p->front == NULL)
    {
        printf("empty queue");
    }
    else
    {
        struct node *temp;
        temp=p->front;
        p->front=p->front->rlink;
        p->front->llink=NULL;
        free(temp);
    }
}

int main()
{
    struct deque1 p;
    while (1)
    {
        int ele;
        int ch;
        printf("\n1..Insert Head..\n");
        printf("2..Insert Tail..\n");
        printf("3..Delete First..\n");
        printf("4..Delete Last..\n");
        printf("5..Display\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            scanf("%d", &ele);
            insertFront(ele, &p);
            break;
        case 2:
            scanf("%d", &ele);
            insertRear(ele, &p);
            break;
        case 3:
            deleteFront(&p);
            break;
        case 5:
            // display(p);
            break;

        default:
            break;
        }
    }
}