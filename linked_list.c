#include<stdio.h>
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//A->B    A->new->B   
void insertNode(Node*A,Node*new){
    new->next=A->next; 
    A->next=new;
}

Node* createNode(int value){
    Node* newNode=malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}

void deleteNextNode(Node* currentNode){
    if(currentNode->next!=NULL){
        Node* deletedNode=currentNode->next;//point at which actually deleted
        currentNode->next=deletedNode->next;
        free(deletedNode);
    }
}
