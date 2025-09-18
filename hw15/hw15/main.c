//
//  main.c
//  hw15
//
//  Created by RayLee on 2025/3/23.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

char* hcf(int a, int b){
    static char res[99];
    int idx = 1;
    if((a < 0 && b < 0) || (a > 0 && b < 0)){
        a *= -1;
        b *= -1;
    }
    for(int i = 2; i <= ((a > b)? a: b); i++){
        if(a % i == 0 && b % i == 0)
            idx = i;
    }
    sprintf(res, "%d/%d", a/idx, b/idx);
    return res;
}

int main(int argc, const char * argv[]) {
    int number = 0;
    scanf("%d", &number);
    for(int i = 0; i < number; i++){
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        char m[99], n[99];
        
        int a = (y1 - y2), b = (x1 - x2);
        if(a % b == 0)
            sprintf(m, "%d", a / b);
        else
            strcpy(m, hcf(a, b));
        a = (x2 * y1 - x1 * y2);
        b = (x2 - x1);
        if(a % b == 0)
            sprintf(n, "%d", a / b);
        else
            strcpy(n, hcf(a, b));
        
        if (strcmp(m, "0") == 0) {  // 斜率為 0
            printf("y = %s\n", n);
        } else {
            printf("y = ");
            if (strcmp(m, "1") == 0) {
                printf("x");
            } else if (strcmp(m, "-1") == 0) {
                printf("-x");
            } else {
                printf("%sx", m);
            }

            if (strcmp(n, "0") != 0) {
                if (n[0] != '-') {
                    printf(" + %s", n);
                } else {
                    printf(" - %s", n+1);
                }
            }
            printf("\n");
        }
        
    }
    return 0;
}
