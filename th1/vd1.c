#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

int chuyenDoi(struct Node* head){
    Node* tmp = head;
    int a = 0;
    while(tmp != NULL){
        a = a * 10 + tmp->data;
        tmp = tmp->next;
    }
    return a;
}

int demSoChuSo(int n){
    if(n == 0) return 1;
    int count = 0;
    while(n > 0){
        count++;
        n /= 10;
    }
    return count;
}

Node* taoListTuSo(int n){
    if(n == 0) return createNode(0);
    int digits[32];
    int cnt = 0;
    while(n > 0){
        digits[cnt++] = n % 10;
        n /= 10;
    }
    Node* head = NULL;
    Node* tail = NULL;
    for(int i = cnt - 1; i >= 0; i--){
        Node* newNode = createNode(digits[i]);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

struct Node* result(Node* head1, Node* head2){
    int so1 = chuyenDoi(head1);
    int so2 = chuyenDoi(head2);
    int tong = so1 + so2;
    int n = demSoChuSo(tong);

    Node* head = NULL;
    Node* tail = NULL;
    for(int i = 0; i < n; i++){
        int chuSo = tong % 10;
        Node* newNode = createNode(chuSo);
        if(head == NULL){
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        tong /= 10;
    }
    return head;
}

int main(){
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    Node* head1 = taoListTuSo(n1);
    Node* head2 = taoListTuSo(n2);
    Node* headResult = result(head1, head2);
    Node* tmp = headResult;
    while(tmp != NULL){
        printf("%d", tmp->data);
        tmp = tmp->next;
    }
    return 0;
}
