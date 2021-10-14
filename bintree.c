#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int data;
    struct BST *rlink;
    struct BST *llink;
};

typedef struct BST BST;

BST *getNode()
{
    BST *temp;
    temp = malloc(sizeof(BST));
    temp->llink = temp->rlink = NULL;
    return temp;
}

BST* insert(int data, BST *root)
{
    BST *temp = getNode();
    temp->data = data;
    if (root == NULL)
    {
        return temp;
    }
    else
    {
        BST *prev = NULL;
        BST *cur = NULL;
        while (cur != NULL)
        {
            prev = cur;
            if (cur->data == temp->data)
            {
                free(temp);
                return root;
            }
            else
            {
                if (cur->data < temp->data)
                {
                    cur = cur->rlink;
                }
                else
                {
                    cur = cur->llink;
                }
            }
        }
        if (temp->data > prev->data)
        {
            // prev->rlink = temp;
        }
        // else
        // {
        //     // prev->llink = temp;
        // }
        return cur;
    }
}

void preorder(BST *root)
{
    // printf(root);
    // if (root->llink == NULL)
    // {
    //     printf(root->rlink);
    //     root = root->rlink;
    //     preorder(root);
    //     return;
    // }
    // else
    // {
    //     root = root->llink;
    //     preorder(root);
    // }

    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", root->data);
        root = root->llink;
        preorder(root->llink);
        preorder(root->rlink);
    }
}

void postorder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d\t", root->data);
        preorder(root->rlink);
        preorder(root->llink);
    }
}

void inorder(BST *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
    }
}

// search, recursively and iteratively, print max.

void max(BST *root)
{
    int m;
    if (root == NULL)
    {
        return;
    }
    else
    {
        m = root->rlink;
        max(root->rlink);
    }
    printf("%d", m);
}

void search(BST *root, int ele)
{
    if (root->data == ele)
    {
        printf("element found\n");
        return;
    }
    else if (ele < root->data)
    {
        search(root->llink, ele);
    }
    else
    {
        search(root->rlink, ele);
    }
}

BST *delete (BST *root, int ele)
{
    BST *cur = root;
    BST *prev = NULL;
    while (cur != NULL && cur->data != ele)
    {
        prev = cur;
        if (ele < cur->data)
        {
            cur = cur->llink;
        }
        else
        {
            cur = cur->rlink;
        }
    }
    if (cur == NULL)
    {
        printf("not found\n");
        return root;
    }
    else
    {
        if (cur->rlink == NULL && cur->llink == NULL)
        {
            free(cur);
        }
        else if (cur->rlink == NULL || cur->llink == NULL)
        {
            BST *q;
            if (cur->llink == NULL)
            {
                q = cur->rlink;
            }
            else
            {
                q = cur->llink;
            }
            if (prev == NULL)
            {
                return q;
            }
            if (cur == prev->llink)
            {
                prev->llink = q;
            }
            else
            {
                prev->rlink = q;
            }
            free(cur);
            return root;
        }
        else if (cur->llink != NULL && cur->rlink != NULL)
        {
            BST *temp;
            BST *p = cur->rlink;
            while (temp->llink!=NULL)
            {
                p=temp;
                temp=temp->llink;
            }
            if(p!=NULL){
                p->llink=temp->rlink;
            }else{
                cur->rlink=temp->rlink;
            }
            cur->data=temp->data;
            free(temp);
            return root;
        }
    }
    return root;
}

BST* create(char *postfix){
    BST *stack[50];
    int top;
    char temp;
    for (int i = 0; temp=stack[i] != '\0'; i++)
    {
        stack[i]=malloc(sizeof(BST));
    }
    
}

int main()
{
    int ele;
    int choice;
    BST *root;
    char *postfix;
    postfix=(char*)malloc(sizeof(char)*100);
    // root = getNode();
    while (1)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the data\n");
            scanf("%d", &ele);
            root = insert(ele, root);
            break;

        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("enter node\n");
            scanf("%d", &ele);
            root = delete (root, ele);
            break;
        case 6:
            printf("postfix expression\n");
            scanf("%s", postfix);
            printf("%c", postfix[1]);
        default:
            break;
        }}