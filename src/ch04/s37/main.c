#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack *create_stack(void) {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, int value) {
    Node *n = malloc(sizeof(Node));
    n->value = value;
    n->next = s->top;
    s->top = n;
}

int pop(Stack *s) {
    if (!s->top) {
        printf("Stack underflow!\n");
        return -1;
    }
    Node *temp = s->top;
    int val = temp->value;
    s->top = temp->next;
    free(temp);
    return val;
}

int peek(const Stack *s) {
    return s->top ? s->top->value : -1;
}

void free_stack(Stack *s) {
    while (s->top) pop(s);
    free(s);
}

int main(void) {
    Stack *s = create_stack();
    push(s, 10);
    push(s, 20);
    push(s, 30);

    printf("Top: %d\n", peek(s));
    printf("Popped: %d\n", pop(s));
    printf("Popped: %d\n", pop(s));
    printf("Top now: %d\n", peek(s));

    free_stack(s);
    return 0;
}
