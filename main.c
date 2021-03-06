#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct doubly
{
    int data;
    struct doubly *rlink;
    struct doubly *llink;
} NODE;

typedef struct list
{
    NODE *head;
} list;

list *initialize()
{
    list *dl = malloc(sizeof(list));
    dl->head = NULL;
    return dl;
}

NODE *create()
{
    NODE *temp = malloc(sizeof(NODE));
    return temp;
}

void insert(list *head, int ele)
{
    NODE *temp;
    temp = create();
    temp->data=ele;
    temp->rlink=temp->llink=NULL;
    if(head==NULL){
        head=temp;
    }else{
        head->rlink->llink=temp;
        temp->llink=head;
        temp->rlink=head->rlink;
        head=temp;
    }
}

int main()
{
    list *dl = initialize();
    int choice;
    int x, ch, pos;
    while (1)
    {
        display(first);
        printf("\n1..Insert Head..\n");
        printf("2..Insert Tail..\n");
        printf("3..Delete First..\n");
        printf("4..Delete Last..\n");
        printf("5..Delete node..\n");
        printf("6..Delete at position\n");
        printf("7..Insert at position\n");
        printf("8..Display\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value..\n");
            scanf("%d", &x);
            insert(dl, x);
            break;
            //     case 2:
            //         printf("Enter the value..\n");
            //         scanf("%d", &x);
            //         insertAtTail(&first, x);
            //         break;
            //     case 3:
            //         deleteAtHead(&first);
            //         break;
            //     case 4:
            //         deleteAtTail(&first);
            //         break;
            //     case 5:
            //         printf("Enter the value..\n");
            //         scanf("%d", &x);
            //         deleteAtVal(&first, x);
            //         break;
            //     case 6:
            //         printf("Enter the position..\n");
            //         scanf("%d", &x);
            //         deleteAtPos(&first, x);
            //         break;
            //     case 7:
            //         printf("Enter the value and position..\n");
            //         scanf("%d %d", &x, &pos);
            //         insertAtPos(&first, x, pos);
            //         break;
            //     case 8:
            //         display(first);
            //         break;
            //     }
            // }
        }