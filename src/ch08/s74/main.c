#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *push(Node *head, int val) {
    Node *n = malloc(sizeof(Node));
    n->value = val;
    n->next = head;
    return n;
}

void test_push(void) {
    Node *head = NULL;
    head = push(head, 10);
    head = push(head, 20);
    assert(head->value == 20);
    assert(head->next->value == 10);
    printf("test_push passed\n");
}

int main(void) {
    test_push();
    printf("All tests passed.\n");
}
