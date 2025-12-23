#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

void xoaCuoi(Node** head){
    if(*head == NULL) return;
    else if ((*head)->next == NULL) *head = NULL;
    else{
        Node* tmp = *head;
        while(tmp->next->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = NULL;
    }
}

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

void themDau(Node** head, int data){
    Node* newNode = createNode(data);
    if(*head == NULL) *head = newNode;
    else{
        newNode->next = *head;
        *head = newNode;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    while(n--){
        int data;
        scanf("%d", &data);
        themDau(&head, data);
    }
    printList(head);
    xoaCuoi(&head);
    printf("\n");
    printList(head);
    return 0;
}