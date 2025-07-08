#include <stdio.h>
#define  MAX 100

typedef struct {
    int data[MAX];
    int top;
}Stack;

void createStack(Stack *stack) {
    stack->top = -1;
}

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

int top(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return stack->data[stack->top];
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return NULL;
    }
    return stack->data[stack->top--];
}

int size(Stack *stack) {
    return stack->top + 1;
}

int main(void) {
    Stack stack;
    createStack(&stack);
    for (int i = 1; i <= 5; i++) {
        push(&stack, i);
    }

    show(&stack);
    printf("\nTop: %d", top(&stack) );
    printf("\npop: %d\n", pop(&stack) );
    show(&stack);
    printf("\nsize: %d\n", size(&stack) );

    return 0;
}