//
//  main.c
//  hw31
//
//  Created by RayLee on 2025/5/18.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 評分類型
typedef enum { G, GPA, S } scoreType_t;
typedef enum { Aplus, A, Aduce, Bplus, B, Bduce, Cplus, C, Cduce, F, X } G_t;
typedef enum { b4dot3, b4dot0, b3dot7, b3dot3, b3dot0, b2dot7, b2dot3, b2dot0, b1dot7, b1, b0 } GPA_t;
typedef enum { b90to100, b85to89, b80to84, b77to79, b73to76, b70to72, b67to69, b63to66, b60to62, b1to59, b0to0 } S_t;

// 學生分數 union
typedef union {
    int score;
    G_t G;
    GPA_t GPA;
    S_t S;
} studentScore_t;

// 學生資料
typedef struct {
    int id;
    studentScore_t scores[4];
    int avg_score;
} student_t;

// 轉換函式
int g_to_score(G_t g) {
    const int table[] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0};
    return table[g];
}
int gpa_to_score(GPA_t gpa) {
    const int table[] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0};
    return table[gpa];
}
int s_to_score(S_t s) {
    const int table[] = {95, 87, 82, 78, 75, 70, 68, 65, 60, 50, 0};
    return table[s];
}

// 字串轉 enum
G_t parse_G(const char *str) {
    if (strcmp(str, "A+") == 0) return Aplus;
    if (strcmp(str, "A") == 0) return A;
    if (strcmp(str, "A-") == 0) return Aduce;
    if (strcmp(str, "B+") == 0) return Bplus;
    if (strcmp(str, "B") == 0) return B;
    if (strcmp(str, "B-") == 0) return Bduce;
    if (strcmp(str, "C+") == 0) return Cplus;
    if (strcmp(str, "C") == 0) return C;
    if (strcmp(str, "C-") == 0) return Cduce;
    if (strcmp(str, "F") == 0) return F;
    return X;
}

GPA_t parse_GPA(const char *str) {
    if (strcmp(str, "4.3") == 0) return b4dot3;
    if (strcmp(str, "4.0") == 0) return b4dot0;
    if (strcmp(str, "3.7") == 0) return b3dot7;
    if (strcmp(str, "3.3") == 0) return b3dot3;
    if (strcmp(str, "3.0") == 0) return b3dot0;
    if (strcmp(str, "2.7") == 0) return b2dot7;
    if (strcmp(str, "2.3") == 0) return b2dot3;
    if (strcmp(str, "2.0") == 0) return b2dot0;
    if (strcmp(str, "1.7") == 0) return b1dot7;
    if (strcmp(str, "1") == 0) return b1;
    return b0;
}

S_t parse_S(const char *str) {
    if (strcmp(str, "90-100") == 0) return b90to100;
    if (strcmp(str, "85-89") == 0) return b85to89;
    if (strcmp(str, "80-84") == 0) return b80to84;
    if (strcmp(str, "77-79") == 0) return b77to79;
    if (strcmp(str, "73-76") == 0) return b73to76;
    if (strcmp(str, "70-72") == 0) return b70to72;
    if (strcmp(str, "67-69") == 0) return b67to69;
    if (strcmp(str, "63-66") == 0) return b63to66;
    if (strcmp(str, "60-62") == 0) return b60to62;
    if (strcmp(str, "1-59") == 0) return b1to59;
    return b0to0;
}

// 排序比較函式
int compare(const void *a, const void *b) {
    return ((student_t *)a)->avg_score - ((student_t *)b)->avg_score;
}

// 主程式
int main() {
    int M, N;
    scoreType_t types[4];
    student_t students[10];
    char type_str[10], score_str[10];

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%s", type_str);
        if (strcmp(type_str, "G") == 0) types[i] = G;
        else if (strcmp(type_str, "GPA") == 0) types[i] = GPA;
        else types[i] = S;
    }

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &students[i].id);
        for (int j = 0; j < M; j++) {
            scanf("%s", score_str);
            switch (types[j]) {
                case G: students[i].scores[j].G = parse_G(score_str); break;
                case GPA: students[i].scores[j].GPA = parse_GPA(score_str); break;
                case S: students[i].scores[j].S = parse_S(score_str); break;
            }
        }
    }

    // 計算平均
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            switch (types[j]) {
                case G: sum += g_to_score(students[i].scores[j].G); break;
                case GPA: sum += gpa_to_score(students[i].scores[j].GPA); break;
                case S: sum += s_to_score(students[i].scores[j].S); break;
            }
        }
        students[i].avg_score = sum / M;
    }

    // 排序
    qsort(students, N, sizeof(student_t), compare);

    // 輸出
    for (int i = 0; i < N; i++) {
        printf("%d %d\n", students[i].id, students[i].avg_score);
    }

    return 0;
}

