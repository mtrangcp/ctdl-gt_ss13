#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct {
    Node *top;
}Stack;

void createStack(Stack* stack) {
    stack->top = NULL;
}

void push(Stack* stack, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
}

void show(Stack* stack) {
    Node* node = stack->top;
    while (node != NULL) {
        printf("%d\t", node->data);
        node = node->next;
    }
}

int main(void) {
    Stack stack;
    createStack(&stack);

    for ( int i = 1; i <= 5; i++ ) {
        push(&stack, i);
    }

    show(&stack);

    return 0;
}