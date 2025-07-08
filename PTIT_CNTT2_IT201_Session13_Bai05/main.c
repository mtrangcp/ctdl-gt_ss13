#include <stdio.h>
#define  MAX 100

typedef struct {
    int data[MAX];
    int top;
    int cap;
}Stack;

int isEmpty(Stack *stack) {
    if (stack->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(Stack *stack) {
    if (stack->top == MAX - 1) {
        return 1;
    }
    return 0;
}

void push(Stack *stack, int data) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = data;
    stack->cap = stack->top + 1;
}

Stack createStack(int max) {
    Stack stack ;
    stack.top = -1;
    for (int i = 1; i <= max; i++) {
        push(&stack, i);
    }
    return stack;
}

void show(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >=0; i--) {
        printf("%d\t", stack->data[i]);
    }
}

int size(Stack *stack) {
    return stack->top + 1;
}

void reverse(Stack *stack) {
    if ( isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for ( int i = 0; i < size(stack)/2; i++) {
        int temp = stack->data[i];
        stack->data[i] = stack->data[size(stack) - 1 - i];
        stack->data[size(stack) - 1 - i] = temp;
    }
}

int main(void) {
    Stack stack = createStack(6);
    show(&stack);
    reverse(&stack);
    printf("\nSau: \n");
    show(&stack);
    return 0;
}