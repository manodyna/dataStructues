// #include "struct.h"

NODE* getNode(){
    NODE* temp=NULL;
    temp = (NODE*)malloc(sizeof(NODE));
    temp->link = NULL;
    return temp;
}

void insertAtHead(int d, NODE **first){
    NODE *new;
    new = getNode();
    if (*first == NULL)
    {
        *first = new;
    }
    else
    {
        new->data = d;
        new->link = *first;
        *first = new;
    }
}

void insertAtTail(int d, NODE **first){
    NODE *new;
    new = getNode();
    new->data=d;
    new->link=NULL;
    NODE *prev;
    prev=getNode();
    if(*first == NULL){
        *first = new;
    }else{
        prev=*first;
        while (prev->link!=NULL)
        {
            prev=prev->link;
        }
        prev->link=new;        
    }
    
}

void deleteAtHead(NODE **first){
   NODE *next;
   if (*first == NULL)
   {
       printf("Empty List..");
   }
   else
   {
       next = *first;
       *first = next->link;
       free(first);
   }
}

// void deleteAtTail(NODE **first){
//     NODE *next;
//     next = getNode();
//     NODE *temp;
//     temp = getNode();
//     temp = *first;
//     if (*first == NULL)
//     {
//         printf("empty list");
//     }
//     else if (temp->link != NULL)
//     {
//         free(first);
//     }
//     else
//     {
//         temp = NULL;
//         next = *first;
//         while (next->link != NULL)
//         {
//             temp = next;
//             next = next->link;
//         }
//         temp->link = NULL;
//         free(next);
//     }
// }

void deleteAtTail(NODE **first){
    NODE *next;
    NODE *prev;
    prev=*first;
    if(first==NULL){
        printf("empty list");
    }else if(prev->link==NULL){
        free(first);
    }else{
        while (prev->link!=NULL)
        {
            next=prev;
            prev=prev->link;
        }
        next->link==NULL;
        free(prev);
        
    }
}


void DisplayAndFree(NODE *first){
    while (first->link!=NULL)
    {
        printf("%d \t",first->data);
        first=first->link;
    }
    printf("%d\t", first->data);   
}