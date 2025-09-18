#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DNode {
    int data;
    struct DNode *front;
    struct DNode *back;
} DNode;
typedef DNode* DNodePtr;

DNodePtr head = NULL;
DNodePtr tail = NULL;

// Add to the front
void addFront(int val) {
    DNodePtr new_node = (DNodePtr)malloc(sizeof(DNode));
    new_node->data = val;
    new_node->front = NULL;
    new_node->back = head;
    if (head) head->front = new_node;
    else tail = new_node;
    head = new_node;
}

// Add to the back
void addBack(int val) {
    DNodePtr new_node = (DNodePtr)malloc(sizeof(DNode));
    new_node->data = val;
    new_node->back = NULL;
    new_node->front = tail;
    if (tail) tail->back = new_node;
    else head = new_node;
    tail = new_node;
}

// Remove from the front
void removeFront() {
    if (!head) {
        printf("Double link list is empty\n");
        return;
    }
    DNodePtr temp = head;
    head = head->back;
    if (head) head->front = NULL;
    else tail = NULL;
    free(temp);
}

// Remove from the back
void removeBack() {
    if (!tail) {
        printf("Double link list is empty\n");
        return;
    }
    DNodePtr temp = tail;
    tail = tail->front;
    if (tail) tail->back = NULL;
    else head = NULL;
    free(temp);
}

// Clear the list
void emptyList() {
    if (!head) {
        printf("Double link list is empty\n");
        return;
    }
    while (head) {
        DNodePtr temp = head;
        head = head->back;
        free(temp);
    }
    tail = NULL;
}

// Insert after the nth node (1-based index)
void insertAfter(int n, int val) {
    DNodePtr current = head;
    for (int i = 1; i < n && current; i++) {
        current = current->back;
    }

    if (!current) {
        printf("Invalid command\n");
        return;
    }

    DNodePtr new_node = (DNodePtr)malloc(sizeof(DNode));
    new_node->data = val;
    new_node->front = current;
    new_node->back = current->back;

    if (current->back)
        current->back->front = new_node;
    else
        tail = new_node;

    current->back = new_node;
}

// Remove the nth node (1-based index)
void removeAt(int n) {
    DNodePtr current = head;
    for (int i = 1; i < n && current; i++) {
        current = current->back;
    }

    if (!current) {
        printf("Invalid command\n");
        return;
    }

    if (current->front)
        current->front->back = current->back;
    else
        head = current->back;

    if (current->back)
        current->back->front = current->front;
    else
        tail = current->front;

    free(current);
}

// Print list from head to tail
void printList() {
    if (!head) {
        printf("Double link list is empty\n");
        return;
    }
    DNodePtr curr = head;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->back;
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char cmd[20];

    for (int i = 0; i < N; i++) {
        scanf("%s", cmd);
        if (strcmp(cmd, "addFront") == 0) {
            int x;
            scanf("%d", &x);
            addFront(x);
        }
        else if (strcmp(cmd, "addBack") == 0) {
            int x;
            scanf("%d", &x);
            addBack(x);
        }
        else if (strcmp(cmd, "removeFront") == 0) {
            removeFront();
        }
        else if (strcmp(cmd, "removeBack") == 0) {
            removeBack();
        }
        else if (strcmp(cmd, "empty") == 0) {
            emptyList();
        }
        else if (strcmp(cmd, "insert") == 0) {
            int n, x;
            scanf("%d %d", &n, &x);
            insertAfter(n, x);
        }
        else if (strcmp(cmd, "remove") == 0) {
            int n;
            scanf("%d", &n);
            removeAt(n);
        }
        else if (strcmp(cmd, "print") == 0) {
            printList();
        }
    }

    return 0;
}
