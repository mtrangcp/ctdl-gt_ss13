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

int check(char str[]) {
    Stack stack;
    stack.top = -1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&stack, str[i]);
        }
        if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
            if (isEmpty(&stack)) {
                printf("Stack is empty\n");
                return 0;
            }

            char topChar = pop(&stack);
            if ((str[i] == ')' && topChar != '(') || (str[i] == ']' && topChar != '[') || (str[i] == '}' && topChar != '{')) {
                return 0;
            }
        }
    }
    if (!isEmpty(&stack)) {
        return 0;
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
    check(str) == 0 ? printf("FALSE") : printf("TRUE");
    return 0;
}