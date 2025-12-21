#include <stdio.h>

int n = 0, stack[100001];

void push(int x)
{
    stack[n] = x;
    n++;
}

void pop()
{
    if (n >= 1)
    {
        n--;
    }
}

int top()
{
    if (n > 0)
    {
        return stack[n - 1];
    }
    return -1;
}

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        push(i);
    }
    printf("Stack sau khi push: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
    
    pop();
    printf("Stack sau khi pop: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\nSo phan tu: %d\n", n);
    
    printf("Phan tu dinh stack: %d\n", top());
    printf("Stack hien tai: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\nSo phan tu: %d\n", n);
    return 0;
}