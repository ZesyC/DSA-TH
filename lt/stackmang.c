#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 100

typedef struct Stack
{
    int arr[max_size];
    int top;
} Stack;

void initStack(Stack *s)
{
    s->top = 0;
}

bool isEmpty(Stack *s)
{
    return s->top == 0;
}

bool isFull(Stack *s)
{
    return s->top == max_size;
}

void push(int val, int arr[], int top)
{
    if (top < max_size)
    {
        top++;
        arr[top] = val;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop_back(int arr[max_size], int top)
{
    return arr[top];
}
