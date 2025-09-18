//
//  main.c
//  hw12
//
//  Created by RayLee on 2025/3/20.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int input_check(char *str){
    int len = (int)strlen(str) - 1;
    if(str[0] != '_' && !isalpha(str[0])) return 0;
    if(str[len] != '_' && !isalpha(str[len])) return 0;
    return 1;
}

int main(int argc, const char * argv[]) {
    char str[2][99];
    int num[2] = {0};
    for(int i = 0; i < 2; i ++){
        fgets(str[i], 99, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }
    for(int i = 0 ; i < 2; i++){
        if(input_check(str[i]) != 1){
            printf("Error\n");
            return 0;
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = (int)strlen(str[i]) - 1; j >= 0; j--){
            printf("%c", str[i][j]);
            if(str[i][j] != ' ')
                num[i]++;
        }
        printf("\n");
    }
    printf("%s\n", (num[0] >= num[1])? str[0]: str[1]);
    return 0;
}
