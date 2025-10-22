#include <stdio.h>
#define max_size 100

typedef struct Stack{
    int arr[max_size];
    int top;
} Stack;

void push(int val, int arr[], int top) {
    if(top < max) {
        arr[top] = val;
        top++;
    } else {
        printf("Stack Overflow\n");
    }
}