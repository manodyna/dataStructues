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

BST *insert(int data, BST *root)
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
        prev = cur;
        while (cur != NULL)
        {

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
            prev->rlink = temp;
        }
        else
        {
            prev->llink = temp;
        }
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
        // root=root->llink;
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
        return ;
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
    if (root == ele)
    {
        printf("element found\n");
        return;
    }
    else if (ele < root->data)
    {
        search(root->llink);
    }
    else
    {
        search(root->rlink);
    }
}

int main()
{
    int ele;
    int choice;
    BST *root;
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

        default:
            break;
        }
    }
}