//
//  main.c
//  hw10
//
//  Created by RayLee on 2025/3/13.
//

#include <stdio.h>
#include <math.h>
#include <string.h>

int C(int a){
    if(a <= 1)
        return 0;
    if(a % 2 == 0)
        return C(a / 2) + 1;
    return C((a+1) / 2) + 1;
}

int main(int argc, const char * argv[]) {
    char input[9];
    scanf("%s", input);
    while(strcmp(input, "-1")){
        int num = 0;
        for(int i = 0; i < 8 ; i++){
            if(input[i] == '1')
                num += pow(2, 7 - i);
        }
        num = C(num);
        for(int i = 0; i < 4; i++){
            if(num >= pow(2, 3 - i)){
                printf("1");
                num -= pow(2, 3 - i);
            }else{
                printf("0");
            }
        }
        printf("\n");
        scanf("%s", input);
    }
    return 0;
}
