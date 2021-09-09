struct node{
    int data;
    struct node *link;
};

typedef struct node NODE;

void insertAtHead(int d, NODE **);
void insertAtTail(int d, NODE**);
void DisplayAndFree(NODE*);
void deleteAtHead(NODE**);
void deleteAtTail(NODE**);