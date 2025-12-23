#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main(){
    int n;
    //scanf("%d", &n);
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    printList(head);
    return 0;
}