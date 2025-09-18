//
//  main.c
//  hw08
//
//  Created by RayLee on 2025/3/6.
//

#include <stdio.h>
#include <math.h>

float Max(float a, float b, float c){
    return fmax(a, fmax(b, c));
}
float Min(float a, float b, float c){
    return fmin(a, fmin(b, c));
}
float Mid(float a, float b, float c){
    return a + b + c - Max(a, b, c) - Min(a, b, c);
}

int main(int argc, const char * argv[]) {
    int total = 0;
    int ans[99][6]= {0};
    scanf("%d", &total);
    for(int i = 0; i < total; i++){
        float a, b, c;
        scanf("%f %f %f", &a, &b, &c);
        if(Max(a, b, c) > (Mid(a, b, c) + Min(a, b, c)) || Min(a, b, c) <= 0){
            ans[i][0] = 1;
        }else{
            if(Max(a, b, c) == Min(a, b, c)) ans[i][1] = 1;
            if(Max(a, b, c) == Mid(a, b, c) || Mid(a, b, c) == Min(a, b, c)) ans[i][2] = 1;
//            printf("%.1f %.1f %.1f\n", pow(Max(a, b, c), 2), pow(Mid(a, b, c), 2), pow(Min(a, b, c), 2));
            if(pow(Max(a, b, c), 2) > (pow(Mid(a, b, c), 2) + pow(Min(a, b, c), 2))) ans[i][3] = 1;
            if(pow(Max(a, b, c), 2) < (pow(Mid(a, b, c), 2) + pow(Min(a, b, c), 2))) ans[i][4] = 1;
            if(pow(Max(a, b, c), 2) == (pow(Mid(a, b, c), 2) + pow(Min(a, b, c), 2))) ans[i][5] = 1;
        }
    }
    char *alert[6] = {"Not Triangle", "Equilateral Triangle", "Isosceles Triangle", "Obtuse Triangle", "Acute Triangle", "Right Triangle"};
    for(int i = 0; i < total; i++){
        for(int j = 0; j < 6; j++){
            if(ans[i][j] == 1) printf("%s\n", alert[j]);
        }
        if((i+1) < total){
            for(int j = 0; j < total ; j++){
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
