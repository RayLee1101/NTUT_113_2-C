#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 201

typedef struct {
    char digits[MAX_DIGITS];
    int len;
    int sign; // 1 for positive, -1 for negative
} BigNum;

// 函數原型聲明
void initBigNum(BigNum* num, char* str);
void removeLeadingZeros(BigNum* num);
int compareAbs(BigNum* a, BigNum* b);
BigNum add(BigNum* a, BigNum* b);
BigNum subtract(BigNum* a, BigNum* b);
BigNum multiply(BigNum* a, BigNum* b);
void printBigNum(BigNum* num);

void initBigNum(BigNum* num, char* str) {
    int len = strlen(str);
    num->sign = 1;
    int start = 0;
    
    if (str[0] == '-') {
        num->sign = -1;
        start = 1;
    }
    
    num->len = len - start;
    memset(num->digits, 0, MAX_DIGITS);
    
    for (int i = 0; i < num->len; i++) {
        num->digits[MAX_DIGITS - 1 - i] = str[len - 1 - i] - '0';
    }
}

void removeLeadingZeros(BigNum* num) {
    while (num->len > 1 && num->digits[MAX_DIGITS - num->len] == 0) {
        num->len--;
    }
}

int compareAbs(BigNum* a, BigNum* b) {
    if (a->len != b->len) return a->len - b->len;
    for (int i = MAX_DIGITS - 1; i >= MAX_DIGITS - a->len; i--) {
        if (a->digits[i] != b->digits[i])
            return a->digits[i] - b->digits[i];
    }
    return 0;
}

BigNum add(BigNum* a, BigNum* b) {
    BigNum result;
    memset(result.digits, 0, MAX_DIGITS);
    
    if (a->sign == b->sign) {
        int carry = 0;
        int max_len = (a->len > b->len ? a->len : b->len);
        result.len = max_len;
        
        for (int i = 0; i < max_len || carry; i++) {
            if (i >= MAX_DIGITS) break;
            int sum = carry;
            if (i < a->len) sum += a->digits[MAX_DIGITS - 1 - i];
            if (i < b->len) sum += b->digits[MAX_DIGITS - 1 - i];
            result.digits[MAX_DIGITS - 1 - i] = sum % 10;
            carry = sum / 10;
            if (i >= result.len) result.len = i + 1;
        }
        result.sign = a->sign;
    } else {
        BigNum temp = *b;
        temp.sign = 1;
        result = subtract(a, &temp);
    }
    
    removeLeadingZeros(&result);
    return result;
}

BigNum subtract(BigNum* a, BigNum* b) {
    BigNum result;
    memset(result.digits, 0, MAX_DIGITS);
    
    if (a->sign != b->sign) {
        BigNum temp = *b;
        temp.sign = a->sign;
        result = add(a, &temp);
    } else {
        int borrow = 0;
        int cmp = compareAbs(a, b);
        
        BigNum* larger = (cmp >= 0) ? a : b;
        BigNum* smaller = (cmp >= 0) ? b : a;
        result.sign = (cmp >= 0) ? a->sign : -a->sign;
        result.len = larger->len;
        
        for (int i = 0; i < result.len; i++) {
            if (i >= MAX_DIGITS) break;
            int diff = larger->digits[MAX_DIGITS - 1 - i] - borrow;
            if (i < smaller->len) diff -= smaller->digits[MAX_DIGITS - 1 - i];
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits[MAX_DIGITS - 1 - i] = diff;
        }
    }
    
    removeLeadingZeros(&result);
    if (result.len == 1 && result.digits[MAX_DIGITS - 1] == 0)
        result.sign = 1;
    return result;
}

BigNum multiply(BigNum* a, BigNum* b) {
    BigNum result;
    memset(result.digits, 0, MAX_DIGITS);
    result.len = 0;
    result.sign = a->sign * b->sign;
    
    for (int i = 0; i < a->len; i++) {
        int carry = 0;
        for (int j = 0; j < b->len || carry; j++) {
            if (MAX_DIGITS - 1 - i - j < 0) break;
            long long temp = result.digits[MAX_DIGITS - 1 - i - j] + carry;
            if (j < b->len) {
                temp += (long long)a->digits[MAX_DIGITS - 1 - i] *
                        b->digits[MAX_DIGITS - 1 - j];
            }
            result.digits[MAX_DIGITS - 1 - i - j] = temp % 10;
            carry = temp / 10;
            if (MAX_DIGITS - 1 - i - j >= MAX_DIGITS - result.len - 1)
                result.len = MAX_DIGITS - (MAX_DIGITS - 1 - i - j);
        }
    }
    
    removeLeadingZeros(&result);
    return result;
}

void printBigNum(BigNum* num) {
    if (num->len == 0) {
        printf("0\n");
        return;
    }
    if (num->sign == -1 && !(num->len == 1 && num->digits[MAX_DIGITS - 1] == 0))
        printf("-");
    for (int i = MAX_DIGITS - num->len; i < MAX_DIGITS; i++) {
        printf("%d", num->digits[i]);
    }
    printf("\n");
}

int main() {
    char num1[102], num2[102];
    BigNum a, b, sum, diff, prod;
    
    if (scanf("%101s", num1) != 1 || scanf("%101s", num2) != 1) {
        printf("Input error\n");
        return 1;
    }
    
    initBigNum(&a, num1);
    initBigNum(&b, num2);
    
    sum = add(&a, &b);
    diff = subtract(&a, &b);
    prod = multiply(&a, &b);
    
    printBigNum(&sum);
    printBigNum(&diff);
    printBigNum(&prod);
    
    return 0;
}
