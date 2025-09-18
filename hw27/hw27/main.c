#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_TOKENS 100
#define MAX_TOKEN_LENGTH 100

int matches(const char *token, const char *keyword) {
    int token_len = strlen(token);
    int key_len = strlen(keyword);

    for (int i = 0; i < token_len; i++) {
        if (token[i] == '\'' || token[i] == '`') return 0;
    }
    
    if (token_len == key_len) {
        return strcmp(token, keyword) == 0;
    }

    if (token_len == key_len + 1 && strchr(".,!?;:", token[token_len - 1])) {
        return strncmp(token, keyword, key_len) == 0;
    }

    return 0;
}

void store_token(const char *input, char *tokens[], char puncts[], int *size) {
    int len = strlen(input);
    tokens[*size] = strdup(input);
    puncts[*size] = (len > 0 && ispunct(input[len - 1])) ? input[len - 1] : '\0';
    (*size)++;
}

void perform_replace(char *tokens[], char puncts[], int size, const char *target, const char *replacement) {
    for (int i = 0; i < size; i++) {
        if (matches(tokens[i], target)) {
            printf("%s", replacement);
            if (puncts[i]) printf("%c", puncts[i]);
        } else {
            printf("%s", tokens[i]);
        }
        if (i < size - 1) printf(" ");
    }
    printf("\n");
}

void insert_before_target(char *tokens[], char puncts[], int size, const char *target, const char *insert) {
    for (int i = 0; i < size; i++) {
        if (matches(tokens[i], target)) {
            printf("%s ", insert);
        }
        printf("%s", tokens[i]);
        if (i < size - 1) printf(" ");
    }
    printf("\n");
}

void insert_after_target(char *tokens[], char puncts[], int size, const char *target, const char *insert) {
    for (int i = 0; i < size; i++) {
        printf("%s", tokens[i]);
        if (matches(tokens[i], target)) {
            printf(" %s", insert);
        }
        if (i < size - 1) printf(" ");
    }
    printf("\n");
}

void remove_target(char *tokens[], char puncts[], int size, const char *target) {
    int first = 1;
    for (int i = 0; i < size; i++) {
        if (!matches(tokens[i], target)) {
            if (!first) printf(" ");
            printf("%s", tokens[i]);
            first = 0;
        }
    }
    printf("\n");
}

void reverse_order(char *tokens[], char puncts[], int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%s", tokens[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
}

int main() {
    char text[1000], target[100], insert[100];
    char *tokens[MAX_TOKENS];
    char puncts[MAX_TOKENS];
    int token_count = 0;

    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    scanf("%s", target);
    scanf("%s", insert);

    char *token = strtok(text, " ");
    while (token && token_count < MAX_TOKENS) {
        store_token(token, tokens, puncts, &token_count);
        token = strtok(NULL, " ");
    }

    perform_replace(tokens, puncts, token_count, target, insert);
    insert_before_target(tokens, puncts, token_count, target, insert);
    insert_after_target(tokens, puncts, token_count, target, insert);
    remove_target(tokens, puncts, token_count, target);
    reverse_order(tokens, puncts, token_count);

    for (int i = 0; i < token_count; i++) {
        free(tokens[i]);
    }

    return 0;
}
