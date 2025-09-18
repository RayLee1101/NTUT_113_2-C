//
//  main.c
//  hw09
//
//  Created by RayLee on 2025/3/13.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 51

// 檢查是否為整數
int isInteger(char *str) {
    int len = strlen(str);
    if (len < 1 || len > 50) return 0;
    
    // 檢查是否為單獨的0
    if (len == 1 && str[0] == '0') return 1;
    
    int negative = 0;
    if (str[0] == '-') {
        negative = 1;
        if (len == 1) return 0;  // 只有負號不行
    }
    
    // 檢查開頭是否為0
    if (str[negative] == '0') return 0;
    
    // 檢查每個字元是否為數字
    for (int i = negative; i < len; i++) {
        if (!isdigit(str[i])) return 0;
    }
    
    return 1;
}

// 檢查是否為浮點數
int isFloat(char *str) {
    int len = strlen(str);
    if (len < 3 || len > 50) return 0;
    
    int negative = 0;
    int dot = 0;
    int dot_pos = -1;
    
    if (str[0] == '-') {
        negative = 1;
        if (len == 2) return 0;  // -x 不行
    }
    
    // 檢查開頭是否為小數點
    if (str[0] == '.') return 0;
    // 檢查結尾是否為小數點
    if (str[len-1] == '.') return 0;
    
    // 檢查每個字元並記錄小數點位置
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') {
            dot++;
            dot_pos = i;
        } else if (!isdigit(str[i])) {
            return 0;
        }
    }
    
    if (dot != 1) return 0;  // 小數點必須恰好一個
    
    // 檢查開頭為0的情況
    if (str[negative] == '0' && dot_pos != 1) return 0;
    
    return 1;
}

// 檢查是否為變數
int isVariable(char *str) {
    int len = strlen(str);
    if (len < 1 || len > 10) return 0;
    
    // 檢查開頭是否為字母或底線
    if (!isalpha(str[0]) && str[0] != '_') return 0;
    
    // 檢查每個字元是否合法
    for (int i = 1; i < len; i++) {
        if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '_')
            return 0;
    }
    
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);
    
    char str[MAX_LENGTH];
    
    for (int i = 0; i < N; i++) {
        scanf("%50s", str); // 直接使用 scanf 讀取字符串，最多 50 個字符
        
        if (isInteger(str)) {
            printf("integer\n");
        } else if (isFloat(str)) {
            printf("float\n");
        } else if (isVariable(str)) {
            printf("variable\n");
        } else {
            printf("string\n");
        }
    }
    
    return 0;
}
