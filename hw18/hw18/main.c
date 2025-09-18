#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j])
                return 0;
        }
    }
    return 1;
}

int cmp(const void *a, const void *b) {
    int *x = (int *)a;
    int *y = (int *)b;
    for(int i = 0; i < 10; i++) { // 假設 m <= 10
        if(x[i] != y[i])
            return x[i] - y[i];
    }
    return 0;
}

int main() {
    int m, input[20], result[99][10], result_count = 0;

    // 輸入 m 和整數序列
    scanf("%d", &m);
    int index = 0;
    while(scanf("%d", &input[index]) == 1) {
        index++;
        if(getchar() == '\n') break;
    }

    // 找出所有符合條件的子序列，計算總數（不去重）
    for(int i = 0; i <= index - m; i++) {
        int arr[10];
        for(int j = 0; j < m; j++) {
            arr[j] = input[i + j];
        }
        if(check(arr, m)) {
            for(int j = 0; j < m; j++) {
                result[result_count][j] = arr[j];
            }
            result_count++;
        }
    }

    // 排序
    qsort(result, result_count, sizeof(result[0]), cmp);

    // 去重
    int unique_count = 0;
    int unique_result[99][10];
    if(result_count > 0) {
        for(int j = 0; j < m; j++) {
            unique_result[0][j] = result[0][j];
        }
        unique_count = 1;
    }
    for(int i = 1; i < result_count; i++) {
        int is_duplicate = 0;
        for(int j = 0; j < m; j++) {
            if(result[i][j] != result[i-1][j]) {
                is_duplicate = 0;
                break;
            }
            is_duplicate = 1;
        }
        if(!is_duplicate) {
            for(int j = 0; j < m; j++) {
                unique_result[unique_count][j] = result[i][j];
            }
            unique_count++;
        }
    }

    // 輸出：總數用 result_count（不去重），子序列用 unique_result（去重）
    printf("%d\n", result_count);
    for(int i = 0; i < unique_count; i++) {
        for(int j = 0; j < m; j++) {
            printf("%d", unique_result[i][j]);
            if(j < m - 1) printf(" ");
        }
        printf("\n");
    }

    return 0;
}
