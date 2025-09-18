//
//  main.c
//  hw11
//
//  Created by RayLee on 2025/3/14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 遞迴函數計算 Gray Code
char* grayCode(int n, int k) {
    // 基本情況 n = 1
    if (n == 1) {
        char* result = (char*)malloc(2 * sizeof(char));
        sprintf(result, "%d", k);
        return result;
    }
    
    // 計算 2^(n-1)
    int half = 1 << (n - 1);
    
    if (k < half) {
        // G(n, k) = 0G(n-1, k)
        char* sub = grayCode(n - 1, k);
        char* result = (char*)malloc((n + 1) * sizeof(char));
        sprintf(result, "0%s", sub);
        free(sub);
        return result;
    } else {
        // G(n, k) = 1G(n-1, 2^n-1-k)
        char* sub = grayCode(n - 1, (1 << n) - 1 - k);
        char* result = (char*)malloc((n + 1) * sizeof(char));
        sprintf(result, "1%s", sub);
        free(sub);
        return result;
    }
}

int main() {
    int n, k;
    while (1) {
        // 讀取輸入
        scanf("%d", &n);
        
        // 檢查是否結束
        if (n == -1) {
            break;
        }
        
        scanf("%d", &k);
        
        // 驗證輸入範圍
        if (k < 0 || k >= (1 << n)) {
            printf("Invalid input: k out of range\n");
            continue;
        }
        
        // 計算並輸出 Gray Code
        char* result = grayCode(n, k);
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
