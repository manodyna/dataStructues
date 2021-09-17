#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int powx;
    struct node *link;
};
typedef struct node NODE;

NODE *getnode()
{
    NODE *temp;
    temp = (NODE *)malloc(sizeof(NODE));
    if (temp == NULL)
    {
        printf("error\n");
        return (NULL);
    }
    else
        return (temp);
}
void read(NODE **poly1)
{
    int coeff, powx, con;
    NODE *temp = getnode();
    *poly1 = temp;
    printf("enter the coeff and powx\n");
    scanf("%d %d", &coeff, &powx);
    temp->coeff = coeff;
    temp->powx = powx;
    temp->link = NULL;
    while (con)
    {
        printf("have more terms press 1 for yes 0 for NO\n");
        scanf("%d", &con);
        if (con)
        {

            temp->link = getnode();
            printf("enter the coeff and powx\n");
            scanf("%d %d", &coeff, &powx);
            temp = temp->link;
            temp->coeff = coeff;
            temp->powx = powx;
            temp->link = NULL;
        }
        else
        {
            break;
        }
    }
}
void display(NODE *poly)
{
    if (poly == NULL)
    {
        printf("list is empty");
    }
    else
    {
        NODE *cur = poly;
        while (cur != NULL)
        {
            printf("%d^%d", cur->coeff, cur->powx);
            printf("+");
            cur = cur->link;
        }
    }
}

NODE *add(NODE *first, NODE *second, NODE **result)
{
    NODE *temp;
    temp = getnode();
    temp->link = NULL;
    *result = temp;
    while (first && second)
    {
        if (first->powx > second->powx)
        {
            temp->coeff = first->coeff;
            temp->powx = first->powx;
            first = first->link;
        }
        else if (first->powx < second->powx)
        {
            temp->coeff = second->coeff;
            temp->powx = second->powx;
            second = second->link;
        }
        else
        {
            temp->coeff = first->coeff + second->coeff;
            temp->powx = first->powx + second->powx;
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
    while (first || second)
    {
        temp->link = getnode();
        temp = temp->link;
        temp->link = NULL;
        if (first)
        {
            temp->coeff = first->coeff;
            temp->powx = first->powx;
            first = first->link;
        }
        else if (second)
        {
            temp->coeff = second->coeff;
            temp->powx = second->powx;
            second = second->link;
        }
    }
    return *result;
}

int main()
{
    NODE *poly1, *poly2, *poly3;
    printf("enter the poly1\n");
    read(&poly1);
    display(poly1);
    printf("enter the poly2\n");
    read(&poly2);
    display(poly2);
    printf(".\n");
    poly3=add(poly1, poly2, &poly3);
    display(poly3);
}
