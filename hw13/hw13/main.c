//
//  main.c
//  hw13
//
//  Created by RayLee on 2025/3/23.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int CharToNum(char str){
    return (isdigit(str))?str - '0': 10 + (str - 'A');
}
char NumToChar(int n){
    return (n >= 10)?(char)n + 'A' - 10: n + '0';
}

int main(int argc, const char * argv[]) {
    char input[99], result[99];
    int num = 0, index = 0, M, N;
    scanf(" %d", &M);
    scanf(" %s", input);
    scanf(" %d", &N);
    for(int i = 0; i < strlen(input); i++)
        num = num * M + CharToNum(input[i]);
    if(num == 0){
        printf("0\n");
        return 0;
    }
    while(num > 0){
        result[index] = NumToChar(num % N);
        num /= N;
        index++;
    }
    for(int i = index - 1; i >= 0; i--)
        printf("%c", result[i]);
    printf("\n");
    
    return 0;
}
