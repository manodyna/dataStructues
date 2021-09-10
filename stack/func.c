// #include "struct.h"
// #include<stddef.h>
void insertAtTop(int ele, stack **top){
    stack *temp= (stack*)malloc(sizeof(stack));
    if(top==NULL){
        *top=temp;
    }else{
        temp->data=ele;
        temp->link=*top;
        *top=temp;
    }
}

void display(stack *top){
    while(top!=NULL){
        printf("%d", top->data);
        top=top->link;
    }
}