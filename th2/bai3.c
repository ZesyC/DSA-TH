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

void themCuoi(Node** head, int val){
    Node* newNode = createNode(val);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        Node* tmp = *head;
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    Node* head = NULL;
    for(int i = 0; i < n; i++){
        int val;
        scanf("%d", &val);
        themCuoi(&head, val);
    }
    printList(head);
    return 0;
}