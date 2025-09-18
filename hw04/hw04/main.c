//
//  main.c
//  hw04
//
//  Created by RayLee on 2025/3/2.
//

#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    float w, h = 0;
    scanf("%f", &w);
    scanf("%f", &h);
    if(w  < 20 || w > 100 || h < 100 || h > 200){
        printf("ERROR\n");
        return 0;
    }
    int bmi = (w / pow(h/100, 2) * 10);
    int ans = 0;
    if(bmi % 10 <= 4){
        ans = (int) bmi / 10;
    }else if (bmi % 10 >= 6){
        ans = (int) bmi / 10 + 1;
    }else{
        ans = (int)(bmi) / 10;
        if(ans % 2 == 0){
            ans++;
        }
    }
    printf("%d\n", ans);
    if(ans < 18){
        printf("too low\n");
    }else if(ans > 24){
        printf("too high\n");
    }
    return 0;
}
