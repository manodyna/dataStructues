struct node{
    int data;
    struct node *link;
};

typedef struct node *NODE;

 void insertAtHead(int data, NODE first);
 NODE insertAtTail(int data, NODE first);
 void deleteAtHead(NODE first);
 void deleteAtTail(NODE first);
 void insertAtPosition(int data, int pos, NODE first);
 void deleteAtPosition(int pos, NODE first);
 void reverse(NODE* p);
 void search();
 void display(NODE p);
 NODE getNode();