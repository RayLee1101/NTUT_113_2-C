//
//  main.c
//  hw32
//
//  Created by RayLee on 2025/5/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student_s {
    char name[50];
    int score;
} student_t;

void input(student_t s[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].score);
    }
}

void getHigh(student_t s[], int n, char name[], int *highScore) {
    *highScore = s[0].score;
    strcpy(name, s[0].name);
    for (int i = 1; i < n; i++) {
        if (s[i].score > *highScore) {
            *highScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

void getLow(student_t s[], int n, char name[], int *lowScore) {
    *lowScore = s[0].score;
    strcpy(name, s[0].name);
    for (int i = 1; i < n; i++) {
        if (s[i].score < *lowScore) {
            *lowScore = s[i].score;
            strcpy(name, s[i].name);
        }
    }
}

int getAverage(student_t s[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += s[i].score;
    }
    return total / n;
}

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int getMedian(student_t s[], int n) {
    int scores[15];
    for (int i = 0; i < n; i++) {
        scores[i] = s[i].score;
    }
    qsort(scores, n, sizeof(int), compare);
    if (n % 2 == 1) {
        return scores[n / 2];
    } else {
        return (scores[n / 2 - 1] + scores[n / 2]) / 2;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    student_t s[15];
    input(s, n);

    char highName[50], lowName[50];
    int highScore, lowScore;

    getHigh(s, n, highName, &highScore);
    getLow(s, n, lowName, &lowScore);
    int avg = getAverage(s, n);
    int median = getMedian(s, n);

    printf("%s %d\n", highName, highScore);
    printf("%s %d\n", lowName, lowScore);
    printf("%d\n", avg);
    printf("%d\n", median);

    return 0;
}
