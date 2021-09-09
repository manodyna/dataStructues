#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node NODE;

int main(){
    NODE* first = NULL;
    NODE* next = NULL;
    NODE* third = NULL;

    first = (NODE*)malloc(sizeof(NODE*));
    next = (NODE*)malloc(sizeof(NODE*));
    third = (NODE*)malloc(sizeof(NODE*));

    first->data = 10;
    first->link = next;
    next->data = 20;
    next->link = third;
    third->data = 30;
    third->link = NULL;

    NODE* new = (NODE*)malloc(sizeof(NODE*));
    // NODE* temp = (NODE*)malloc(sizeof(NODE*));
    new->data=40;

    while(first->link != NULL){
        first = first->link;
        first->link = new;
        new->link = NULL;
    }

    while(first != NULL){
        printf("%d\t", first->data);
        first = first->link;
    }
    while(first != NULL){
        first = first->link;
        free(first);
    }
}
