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

void xoaDau(Node** head){
    if(*head == NULL){
        return;
    }
    else{
        *head = (*head)->next;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int data;
        scanf("%d", &data);
        Node* newNode = createNode(data);
        newNode->next = head;
        head = newNode;
    }
    for(int i = 0; i < m; i++){
        xoaDau(&head);
    }
    printList(head);
    return 0;
}