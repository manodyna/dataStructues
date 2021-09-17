struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};
typedef struct node NODE;

NODE* getNode();
void insertAtHead(NODE **, int data);
void insertAtTail(NODE **, int data);
void deleteAtHead(NODE **);
void deleteAtTail(NODE **);
void deleteAtPos(NODE **, int pos);
void deleteAtVal(NODE **, int val);
void insertAtPos(NODE **, int pos, int data);
void display(NODE *);