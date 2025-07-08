#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    if ( s->top == -1 ) return 1;
    return 0;
}

int isFull(Stack *s) {
    if ( s->top == MAX - 1 ) return 1;
    return 0;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack full\n");
        return;
    }
    s->data[++s->top] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return 0;
    }
    return s->data[s->top--];
}

int evaluatePostfix(char str[]) {
    Stack s;
    init(&s);

    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];

        if (isdigit(ch)) {
            push(&s, ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = pop(&s);
            int a = pop(&s);
            int result;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main(void) {
    char str[MAX];
    printf("Nhap bieu thuc hau to (postfix): ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    int result = evaluatePostfix(str);
    printf("Gia tri bieu thuc: %d\n", result);

    return 0;
}