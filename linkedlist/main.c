#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "func.c"

int main(){
    NODE first=getNode();
    NODE* a;
    int data, pos;
    printf("1: insert at head \n2: insert at tail \n3:delete at head \n4:delete at tail \n5:insert at position \n6:delete at position \n7:reverse \n8:display \n9:exit \n");
        int c;
    while(1){
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("enter data");
            scanf("%d", &data);
            insertAtHead(data, first);
            break;
        case 2:
            printf("enter data");
            scanf("%d", &data);
            insertAtTail(data, first);
            break;
        case 3:
            deleteAtHead(first);
            break;
        case 4:
            deleteAtTail(first);
            break;
        case 5:
            printf("enter data");
            scanf("%d", &data);
            printf("enter pos");
            scanf("%d", &pos);
            insertAtPosition(data, pos, first);
        case 6:
            scanf("%d", &pos);
            printf("enter pos");
            deleteAtPosition(pos, first);
            break;
        case 7:
            reverse(a);
            break;
        case 8:
            display(first);
        // case 9:
        //     // exit(0);
        // default:
        //     printf("null");
        //     break;
        }
    }
}