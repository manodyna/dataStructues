// #include "struct.h";
// #include <stdlib.h>

NODE* getNode(){
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->rlink=temp->llink=NULL;
    return temp;
}
void insertAtHead(NODE **first, int d)
{
    NODE *temp = getNode();
    temp->data = d;
    if (*first == NULL)
    {
        *first = temp;
        temp->rlink=temp->llink=temp;
    }
    else
    {
        temp->rlink = *first;
        temp->llink = NULL;
        (*first)->llink = temp;
        *first=temp;
    }
    // NODE *temp=getNode();
	// temp->data=d;
	// temp->rlink=temp->llink=temp;
	// if(*first==NULL)
	// 	*first=temp;
	// else{
	// 	NODE *last=(*first)->llink;
	// 	temp->rlink=*first;
	// 	(*first)->llink=temp;
	// 	last->rlink=temp;
	// 	temp->llink=last;
	// 	*first=temp;
	// }
}
void insertAtTail(NODE **first, int d)
{ 
}
void deleteAtHead(NODE **first)
{
}
void deleteAtTail(NODE **first)
{
}
void deleteAtPos(NODE **first, int pos)
{
}
void deleteAtVal(NODE **first, int val)
{
}
void insertAtPos(NODE **first, int pos, int d)
{
}
void display(NODE *first)
{
    if(first==NULL){
        printf("empty list do something");
    }else{
        while(first!=NULL){
            printf("%d\t", first->data);
            first=first->llink;
        }
    }
}