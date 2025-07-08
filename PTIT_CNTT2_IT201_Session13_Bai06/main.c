#include <stdio.h>
#include <string.h>
#define  MAX 100

typedef struct {
    char data[MAX];
    int top;
}Stack;

int isEmpty(Stack *stack) {
    if (stack->top == -1) return 1;
    return 0;
}

int isFull(Stack *stack) {
    if (stack->top == MAX - 1) return 1;
    return 0;
}

void push(Stack *stack, char data) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = data;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

int checkSymmetrical(char str[]) {
    Stack stack;
    stack.top = -1;

    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }
    for ( int i = 0; i < strlen(str); i++) {
        char c = pop(&stack);
        if (c == '\0' || str[i] != c) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char str[MAX];
    printf("Nhap chuoi: ");
    fgets(str, MAX, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    checkSymmetrical(str) == 0 ? printf("FALSE") : printf("TRUE");
    return 0;
}