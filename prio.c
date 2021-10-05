#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct prio
{
    int data;
    int priority;
};

typedef struct prio prio;

void insert(int data, int pri, prio *p, int *count)
{
    prio temp;
    temp.data = data;
    temp.priority = pri;
    int j = *count - 1;
    while (j >= 0 && (p[j].priority) > temp.priority)
    {
        p[j + 1] = p[j];
        j--;
    }
    p[j + 1] = temp;
    (*count)++;
}

prio delete (int *p, int *count)
{
    prio temp;
    if (*count == 0)
    {
        temp.data = -1;
        temp.priority = -1;
    }
    else
    {
        int tem = p[0];
        for (int i = 1; i <= *count-1; i++)
        {
            p[i - 1] = p[i];
        }
        (*count)--;
    }
    return temp;
}

void display(int count, prio *p){
    if(count==0){
        printf("empty");
    }else{
        for (int i=0 ; i < count; i++)
        {
           printf("%d\t", p[i].data);
        }
        
    }
}

int main()
{
    prio p[100];
    prio temp;
    int i, ele, pri, choice, count = 0;
    while (1)
    {
        printf("\n1..Insert Head..\n");
        printf("2..Insert Tail..\n");
        printf("3..Delete First..\n");
        printf("4..Delete Last..\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("%d %d", &ele, &pri);
            insert(ele, pri, p, &count);
            break;
        case 2:
            temp = delete (p, &count);
            break;
        case 3:
            display(count, p) ;
            break;

        default:
            break;
        }
    }
}