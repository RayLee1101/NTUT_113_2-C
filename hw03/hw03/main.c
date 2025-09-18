//
//  main.c
//  hw03
//
//  Created by RayLee on 2025/3/2.
//

#include <stdio.h>
#include <math.h>


int main(int argc, const char * argv[]) {
    char c[7] = {'g','f','e','d','c','b','a'};
    char s[2][7] = {{0}, {0}};
    int s_int[2] = {0, 0};
    char e[2] = {0, 0};
    
    scanf("%d", &s_int[0]);
    scanf("%d", &s_int[1]);
    scanf("\n%c", &e[0]);
    scanf("\n%c", &e[1]);
    int status = 1;
    if(s_int[0] < 0 || s_int[0] > 63){
        printf("S0 ERROR\n");
        status = 0;
    }
    if(s_int[1] < 0 || s_int[1] > 63){
        printf("S1 ERROR\n");
        status = 0;
    }
    for(int i = 0; i < 2; i++){
        int st = 0;
        for(int j = 0;j < 8; j++){
            if(e[i] == c[j]){
                st = 1;
            }
        }
        if(st == 0){
            printf("e%d ERROR\n", i + 1);
            status = 0;
        }
    }
    
    if (status == 0) {
        return  0;
    }
    
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 7; j++){
            if(s_int[i] >= (int)pow(2, 6 - j)){
                s_int[i] -= (int)pow(2, 6 - j);
                s[i][j] = c[j];
            }
        }
    }
    
    char s2[7] = {0};
    for(int i = 0 ; i < 7; i++){
        if(c[i] == e[0] || s[1][i] != 0){
            s2[i] = c[i];
        }
    }
    
    int state = 0;
    for(int i =0; i < 7; i ++){
        if(s2[i] == e[1]){
            state = 1;
        }
    }
    printf("%c\n", (state == 1)?'Y':'N');
    
    state = 1;
    int ans1 = 0, ans2 = 0, ans3 = 0;
    for(int i = 0; i < 7; i++){
        if(s2[i] != 0 && s[0][i] == 0){
            state = 0;
        }
        if(s[0][i] != 0 && s2[i] != 0){
            ans1 += pow(2, 6 - i);
        }
        if(s[0][i] != 0 || s2[i] != 0){
            ans2 += pow(2, 6 - i);
        }
        if(s[0][i] != 0 && s2[i] == 0 ){
            ans3 += pow(2, 6 - i);
        }
    }
    printf("%c\n", (state == 1)?'Y':'N');
    printf("%d\n%d\n%d\n", ans1, ans2, ans3);
    
    
    return 0;
}
