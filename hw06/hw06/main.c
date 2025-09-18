//
//  main.c
//  hw06
//
//  Created by RayLee on 2025/3/6.
//

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    float a = 0, b = 0;
    char c[20];
    char *number[13] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for(int i = 0; i < 3; i++){
        scanf("%s", c);
        for(int j = 0; j < 13; j++){
            if(strcmp(c, number[j]) == 0){
                a += (j < 10)? j+1: 0.5;
            }
        }
    }
    if(a > 10.5) a = 0;
    
    for(int i = 0; i < 3; i++){
        scanf("%s", c);
        for(int j = 0; j < 13; j++){
            if(strcmp(c, number[j]) == 0){
                b += (j < 10)? j+1: 0.5;
            }
        }
    }
    if(b > 10.5) b = 0;
    
    (fmod(a, 1) != 0)?printf("%.1f\n", a):printf("%d\n", (int)a);
    (fmod(b, 1) != 0)?printf("%.1f\n", b):printf("%d\n", (int)b);
    printf((a == b)?"Tie\n":(a > b)?"X Win\n":"Y Win\n" );
    
    return 0;
}
