//
//  main.c
//  hw28
//
//  Created by RayLee on 2025/5/11.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    int num = 0, n = 0, result[99] = {0}, max = 1, eng_size = -1, now = 1, before_eng_size = -1;
    char eng[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        char str[99] = {'\0'};
        scanf("%s", str);
        scanf("%d", &n);
        for (int j = 0; j < strlen(str); j++) {
            int big = 0;
            for (int l = 0; l < 26; l++)
                if(eng[l] == str[j]) big = 1;
            if(big != eng_size){
                if(now <= n && big == before_eng_size){
                    
                }else{
                    now = 1;
                    eng_size = (n == 1)?(big == 1)?0:1:big;
                }
            }else{
                now++;
                before_eng_size = eng_size;
                if(now % n == 0)eng_size = (eng_size == 1)?0:1;
                max = (max > now)?max: now;
            }
        }
        max = (max > now)?max: now;
        result[i] = (max - (max % n) > n)? max - (max % n): 0;
        before_eng_size = -1;
        eng_size = -1;
        now = 1;
        max = 1;
    }
    for (int i = 0; i < num; i++) {
        printf("%d\n", result[i]);
    }
}
