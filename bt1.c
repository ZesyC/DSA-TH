#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head){
    Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void themNode(Node** head, int data){
    Node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void loaiTrung(Node **head){
    if (head == NULL || *head == NULL) return;

    Node *temp = *head;
    while (temp != NULL){
        Node *prev = temp;
        Node *temp2 = temp->next;
        while (temp2 != NULL){
            if (temp2->data == temp->data){
                prev->next = temp2->next;
                free(temp2);
                temp2 = prev->next;
            } else {
                prev = temp2;
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int L = -10, R = 10;

    srand((unsigned)time(NULL));

    Node* head = NULL;
    for (int i = 0; i < n; ++i){
        int x = L + rand() % (R - L + 1);
        themNode(&head, x);
    }
    printList(head);
    loaiTrung(&head);
    printList(head);
    return 0;
}