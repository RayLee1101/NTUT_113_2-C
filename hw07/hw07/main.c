//
//  main.c
//  hw07
//
//  Created by RayLee on 2025/3/7.
//

#include <stdio.h>
#include <ctype.h>

void pattern1(int M) {
    char letter = 'A'-1;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M - i - 1; j++) printf("#");
        for (int j = 0; j < i + 1; j++) {
            printf("*");
            if (j < i) printf("%c", letter);
        }
        for (int j = 0; j < M - i - 1; j++) printf("#");
        letter = (letter - 'A' + 1) % 3 + 'A';
        printf("\n");
    }
}

void pattern2(int M) {
    for (int i = 0; i < M; i++) {
        for (int j = i + 1; j > 0; j--) printf("%d", j);
        for (int j = 0; j < (M - i) * 2; j++) printf("*");
        for (int j = 1; j <= i + 1; j++) printf("%d", j);
        printf("\n");
    }
}

int main() {
    int N, M;
    if (scanf("%d %d", &N, &M) != 2 || N < 1 || N > 2 || M < 2 || M > 9) {
        printf("error\n");
        return 0;
    }
    
    if (N == 1) pattern1(M);
    else if (N == 2) pattern2(M);
    else printf("error\n");
    
    return 0;
}

