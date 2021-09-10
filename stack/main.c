
#include <stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include "struct.h"
#include "func.c"

int main(){
    stack *top;
    top=(stack*)malloc(sizeof(stack));
    insertAtTop(2,&top);
    // deleteAtTop();
    display(top);
}