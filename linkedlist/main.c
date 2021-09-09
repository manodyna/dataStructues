#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
#include "func.c"

int main(){
    NODE* first;
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
            insertAtHead(data, &first);
            break;
        case 2:
            printf("enter data");
            scanf("%d", &data);
            insertAtTail(data, &first);
            break;
        case 3:
            printf("delete at head\n");
            deleteAtHead(&first);
            break;
        case 4:
            printf("delete at tail\n");
            deleteAtTail(&first);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            DisplayAndFree(first);
            break;
        case 9:
            exit(0);
        }
    }
}