#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;
typedef Node* NodePtr;

// Stack variables
NodePtr stack_top = NULL;

// Stack functions
void stack_push(int value) {
    NodePtr new_node = (NodePtr)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = stack_top;
    stack_top = new_node;
}

void stack_pop() {
    if (!stack_top) {
        printf("Stack is empty\n");
        return;
    }
    NodePtr temp = stack_top;
    printf("%d\n", temp->data);
    stack_top = stack_top->next;
    free(temp);
}

void stack_top_func() {
    if (!stack_top) {
        printf("Stack is empty\n");
    } else {
        printf("%d\n", stack_top->data);
    }
}

void stack_empty() {
    if (!stack_top) {
        printf("Stack is empty\n");
        return;
    }
    NodePtr temp;
    while (stack_top) {
        temp = stack_top;
        stack_top = stack_top->next;
        free(temp);
    }
}

void stack_print() {
    if (!stack_top) {
        printf("Stack is empty\n");
        return;
    }
    NodePtr curr = stack_top;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

// Queue variables
NodePtr queue_front = NULL, queue_rear = NULL;

// Queue functions
void queue_push(int value) {
    NodePtr new_node = (NodePtr)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if (!queue_rear) {
        queue_front = queue_rear = new_node;
    } else {
        queue_rear->next = new_node;
        queue_rear = new_node;
    }
}

void queue_pop() {
    if (!queue_front) {
        printf("Queue is empty\n");
        return;
    }
    NodePtr temp = queue_front;
    printf("%d\n", temp->data);
    queue_front = queue_front->next;
    if (!queue_front) queue_rear = NULL;
    free(temp);
}

void queue_front_func() {
    if (!queue_front) {
        printf("Queue is empty\n");
    } else {
        printf("%d\n", queue_front->data);
    }
}

void queue_empty() {
    if (!queue_front) {
        printf("Queue is empty\n");
        return;
    }
    NodePtr temp;
    while (queue_front) {
        temp = queue_front;
        queue_front = queue_front->next;
        free(temp);
    }
    queue_rear = NULL;
}

void queue_print() {
    if (!queue_front) {
        printf("Queue is empty\n");
        return;
    }
    NodePtr curr = queue_front;
    while (curr) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

// Main
int main() {
    int N, val;
    char type[10], cmd[10];

    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%s %s", type, cmd);

        if (strcmp(type, "stack") == 0) {
            if (strcmp(cmd, "push") == 0) {
                scanf("%d", &val);
                stack_push(val);
            } else if (strcmp(cmd, "pop") == 0) {
                stack_pop();
            } else if (strcmp(cmd, "top") == 0) {
                stack_top_func();
            } else if (strcmp(cmd, "empty") == 0) {
                stack_empty();
            } else if (strcmp(cmd, "print") == 0) {
                stack_print();
            }
        } else if (strcmp(type, "queue") == 0) {
            if (strcmp(cmd, "push") == 0) {
                scanf("%d", &val);
                queue_push(val);
            } else if (strcmp(cmd, "pop") == 0) {
                queue_pop();
            } else if (strcmp(cmd, "front") == 0) {
                queue_front_func();
            } else if (strcmp(cmd, "empty") == 0) {
                queue_empty();
            } else if (strcmp(cmd, "print") == 0) {
                queue_print();
            }
        }
    }

    return 0;
}
