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

void bubbleSortData(Node* head){
    if (!head) return;

    int swapped;
    do {
        swapped = 0;
        Node *p = head, *q = head->next;
        while (q != NULL) { 
            if (p->data > q->data) {
                int tmp = p->data;
                p->data = q->data;
                q->data = tmp;
                swapped = 1;
            }
            p = q;
            q = q->next;
        }
    } while (swapped);
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
    bubbleSortData(head);
    printList(head);
    return 0;
}