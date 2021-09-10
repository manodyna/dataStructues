struct stack{
    int data;
    struct stack* link;
};
typedef struct stack stack;
void insertAtFront(int elem, stack**);
void deleteAtTop(stack**);
void display(stack*);