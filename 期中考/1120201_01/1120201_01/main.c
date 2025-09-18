//
//  main.c
//  1120201_01
//
//  Created by RayLee on 2025/4/15.
//

#include <stdio.h>
#include <stdlib.h>

void fun1(int num, int number){
    if(num <= number){
        for(int i = 0; i < num; i++)
            printf("%d", i + 1);
    }else{
        num = number * 2 - num;
        for(int i = num; i >= 0; i--)
            printf("%d", i + 1);
    }
    printf("\n");
}
void fun2(int num, int number){
    if(num > number)
        num = number * 2 - num;
    for(int i = 0; i < number - num; i++)
        printf("_");
    for(int i = num; i > 0; i--)
        printf("%d", i);
    for(int i = 2; i <= num; i++)
        printf("%d", i);
    for(int i = 0; i < number - num; i++)
        printf("_");

    printf("\n");
}
void fun3(int num, int number){
    for(int i = 1; i < num; i++)
        printf("%d", i);
    for(int i = num; i > 0; i--)
        printf("%d", i);
    for(int i = 0; i < (number - num) * 2; i++)
        printf("_");
    printf("\n");
}
void fun4(int num, int number){
    for(int i = 0; i < num; i++)
        printf("_");
    if(num % 2 == 0){
        for(int i = 0; i < number; i++)
            printf("%d", i + 1);
    }else{
        for(int i = number; i > 0; i--)
            printf("%d", i);
    }
    for(int i = 0; i < number - num - 1; i++)
        printf("_");
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int mode = 0, number = 0;
    scanf("%d", &mode);
    scanf("%d", &number);
    if(mode == 1){
        for(int i = 1; i < number * 2 + 1; i++)
            fun1(i, number);
    }else if(mode == 2){
        for(int i = 1; i < number * 2; i++)
            fun2(i, number);
    }else if(mode == 3){
        for(int i = 0; i < number; i++)
            fun3(i + 1, number);
    }else{
        for(int i = 0; i < number; i++)
            fun4(i, number);
    }
    return 0;
}
