#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

Node* insert_term(Node* head, int coeff, int exp) {
    if (coeff == 0) return head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;

    if (!head || exp > head->exp) {
        newNode->next = head;
        return newNode;
    }

    Node *curr = head, *prev = NULL;
    while (curr && curr->exp > exp) {
        prev = curr;
        curr = curr->next;
    }

    if (curr && curr->exp == exp) {
        curr->coeff += coeff;
        if (curr->coeff == 0) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            free(curr);
        }
        free(newNode);
        return head;
    }

    newNode->next = curr;
    if (prev) prev->next = newNode;
    else head = newNode;
    return head;
}

Node* build_poly_from_input() {
    char line[1024];
    fgets(line, sizeof(line), stdin);
    int nums[100], count = 0;
    char *token = strtok(line, " \n");
    while (token != NULL) {
        nums[count++] = atoi(token);
        token = strtok(NULL, " \n");
    }

    Node* head = NULL;
    for (int i = 0; i < count; i++) {
        int exp = count - i - 1;
        head = insert_term(head, nums[i], exp);
    }
    return head;
}

Node* add_poly(Node* a, Node* b) {
    Node* result = NULL;
    while (a) {
        result = insert_term(result, a->coeff, a->exp);
        a = a->next;
    }
    while (b) {
        result = insert_term(result, b->coeff, b->exp);
        b = b->next;
    }
    return result;
}

void print_poly(Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }

    int first = 1;
    while (head) {
        int c = head->coeff;
        int e = head->exp;

        if (c == 0) {
            head = head->next;
            continue;
        }

        if (!first) {
            if (c > 0) printf("+");
            else printf("-");
        } else {
            if (c < 0) printf("-");
        }

        if (abs(c) != 1 || e == 0)
            printf("%d", abs(c));

        if (e > 1) printf("x^%d", e);
        else if (e == 1) printf("x");

        head = head->next;
        first = 0;
    }
    printf("\n");
}

int main() {
    Node* p1 = build_poly_from_input();
    Node* p2 = build_poly_from_input();
    Node* result = add_poly(p1, p2);
    print_poly(result);
    return 0;
}
