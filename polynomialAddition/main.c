#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct node
{
    int coeff;
    int pow;
    struct node *link;
};
typedef struct node NODE;

NODE *getnode()
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    return temp;
}

void read(NODE **poly1)
{
    NODE *temp = getnode();
    *poly1 = temp;
    int con = 0;
    printf("enter coeff and pow");
    int coeff, pow;
    scanf("%d %d", &coeff, &pow);
    temp->coeff = coeff;
    temp->pow = pow;
    temp->link = NULL;
    printf("..");
    scanf("%d", &con);

    while (con)
    {

        temp->link = getnode();
        printf("enter coeff and pow");
        int coeff, pow;
        scanf("%d %d", &coeff, &pow);
        temp->coeff = coeff;
        temp->pow = pow;
        temp->link = NULL;
        printf("..");
        scanf("%d", &con);
        if (con == 0)
        {
            break;
        }
    }
}

void display(NODE *poly)
{
    if (poly == NULL)
    {
        printf("empty");
    }
    else
    {
        NODE *temp = poly;
        while (temp != NULL)
        {
            printf("%d %d", temp->coeff, temp->pow);
            temp = temp->link;
        }
    }
}

NODE* add(NODE *first, NODE *second, NODE **result)
{
    NODE *temp = getnode();
    temp->link = NULL;
    *result = temp;
    while (first && second)
    {
        if (first->pow > second->pow)
        {
            temp->coeff = first->coeff;
            temp->pow = first->pow;
            first = first->link;
        }
        else if (first->pow < second->pow)
        {
            temp->coeff = second->coeff;
            temp->pow = second->pow;
            second = second->link;
        }
        else
        {
            temp->coeff = first->coeff + second->coeff;
            temp->pow = first->pow + second->pow;
            first = first->link;
            second = second->link;
        }

        if (first && second)
        {
            temp->link = getnode();
            temp = temp->link;
            temp->link = NULL;
        }
    }
    while(first || second){
        temp->link=getnode();
        temp=temp->link;
        temp->link=NULL;
        if (first)
        {
            temp->coeff=first->coeff;
            temp->pow=first->link;
            first=first->link;
        }else if(second){
            temp->coeff=second->coeff;
            temp->pow=second->link;
            second=second->link;
        }
        
    }
}

// void eval(NODE* first){
//     int sum=0;
//     NODE *cur=first;
//     int x;
//     scanf("%d",&x);
//     while(cur!=NULL){
//         sum+=
//     }
// }

int main()
{
    NODE *poly1;
    NODE *poly2;
    NODE *poly3;

    printf("enter poly1");
    read(&poly1);
    printf("enter poly2");
    read(&poly2);
    poly3=add(poly1, poly2, &poly3);
    display(poly3);
}