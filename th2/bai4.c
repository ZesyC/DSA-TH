#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    Node* tmp = head;
    while(tmp != NULL){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}

void themGiua(Node** head, int val, int before){
    Node* newNode = createNode(val);
    Node* tmp = *head;
    if(*head == NULL){
        *head = newNode;
    }
    else{
        while(tmp != NULL && tmp->val != before){
            tmp = tmp->next;
        }
        if(tmp == NULL){
            newNode->next = *head;
            *head = newNode;
        }
        else{
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int val, before;
        scanf("%d %d", &val, &before);
        themGiua(&head, val, before);
    }
    printList(head);
    return 0;
}