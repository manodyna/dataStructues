//   #include "struct.h"
  #include <stdio.h>
  #include <stdlib.h> 

 NODE getNode(){
     NODE temp;
     temp=(NODE)malloc(sizeof(struct node));
     temp->data=0;
     temp->link= NULL;
     return temp;
 }

 void insertAtHead(int d, NODE first){
     NODE temp = getNode();
     temp->data = d;
     if (first== NULL)
     {
        first=temp;
     }else{
         temp->link = first;
         first=temp;
     }
     
 }

 NODE insertAtTail(int d, NODE first){
     NODE temp, p;
     temp = getNode();
     temp->data = d;
     if(first == NULL){
         first=temp;
     }else{
         p=first;
         while(p->link != NULL){
             p=p->link;
         }
         p->link=temp;
        }
        return first;
    }


 void deleteAtHead(NODE first){

 }

 void deleteAtTail(NODE first){

 }

 void insertAtPosition(int data, int pos, NODE first){

 }

 void deleteAtPosition(int pos, NODE first){

 }

 void reverse(NODE* p){

 }

 void search(){

 }

 void display(NODE p){
     while (p!=NULL)
     {
         p=p->link;
        printf("%d", p->data);
     }
     
 }
 