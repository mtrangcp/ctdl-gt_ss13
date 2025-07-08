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
        int n;
        printf("Nhap so thu %d: ", i);
        scanf("%d", &n);
        push(&stack, n);
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

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top--];
}

int main(void) {
    Stack stack = createStack(0);
    show(&stack);
    if ( pop(&stack) == -1 ) {
        printf("No element in stack\n");
    }else {
        printf("\n%d", pop(&stack));
    }

    return 0;
}