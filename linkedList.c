#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    struct node_t *previous;
    int data;
    struct node_t *next;
} node_t;

node_t *insertBeginning(node_t *head, int data);
node_t *insertEnd(node_t *head, int data);
void printLinkedList(node_t *head);
node_t *deleteValue(node_t *head, int data);
node_t *popValue(node_t *head);

int main() {
    node_t *head = (node_t *)malloc(sizeof(node_t));
    head->previous = NULL;
    head->data = 100000;
    head->next = NULL;

    head = insertEnd(head, 100001);
    head = insertBeginning(head, 100010);
    head = insertEnd(head, 100011);
    head = insertEnd(head, 100100);
    printLinkedList(head);
    head = popValue(head);
    head = insertEnd(head, 100101);
    head = insertEnd(head, 100110);
    printLinkedList(head);

    return 0;
}

node_t *insertBeginning(node_t *head, int data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = head;
    node->previous = NULL;

    if (head != NULL) {
        head->previous = node;
    }

    printf("%d value is inserted to the beginning.\n", data);
    return node;
}

node_t *insertEnd(node_t *head, int data) {
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;

    if (head == NULL) {
        node->previous = NULL;
        printf("%d value is inserted to the end.\n", data);
        return node;
    }

    node_t *temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = node;
    node->previous = temp;

    printf("%d value is inserted to the end.\n", data);
    return head;
}

void printLinkedList(node_t *head) {
    node_t *temp = head;
    while (temp) {
        printf("Node's data: %d\n", temp->data);
        temp = temp->next;
    }
}

node_t *deleteValue(node_t *head, int data) {
    node_t *temp = head;

    while (temp && temp->data != data) {
        temp = temp->next;
    }

    if (!temp) return head;

    if (temp->previous) {
        temp->previous->next = temp->next;
    }
    else {
        head = temp->next;
    }

    if (temp->next) {
        temp->next->previous = temp->previous;
    }

    free(temp);
    return head;
}

node_t *popValue(node_t *head) {
    if (!head) return NULL;

    node_t *temp = head;
    while (temp->next) {
        temp = temp->next;
    }

    printf("Node with %d value is popped.\n", temp->data);

    if (temp->previous) {
        temp->previous->next = NULL;
    }
    else {
        head = NULL;
    }

    free(temp);
    return head;
}
