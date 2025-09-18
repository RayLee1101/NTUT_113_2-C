//
//  main.c
//  hw14
//
//  Created by RayLee on 2025/3/23.
//

#include <stdio.h>

void find_greatest_common_divisor(int *x, int *y, int *gcd){
    if (*y == 0){
        *gcd = *x;
    }else{
        int remainder = *x % *y;
        find_greatest_common_divisor(y, &remainder, gcd);
    }
}

void convert_to_numbers(char *str, int *num){
    if (sscanf(str, "%d(%d/%d)", num, num+1, num+2) == 3){
        if (*num > 0){
            *(num+1) += *num * *(num+2);
        }else{
            *(num+1) = -*(num+1) + (*num * *(num+2));
        }
    }else{
        sscanf(str, "%d/%d", num+1, num+2);
    }
    *num = 0;
}

void addition(int *fra_1, int *fra_2, int *result){
    int gcd;
    find_greatest_common_divisor(fra_1+2, fra_2+2, &gcd);
    *(result+1) = (*(fra_1+1) * *(fra_2+2) / gcd) + (*(fra_2+1) * *(fra_1+2) / gcd);
    *(result+2) = *(fra_1+2) * *(fra_2+2) / gcd;
}

void subtraction(int *fra_1, int *fra_2, int *result){
    *(fra_2+1) *= -1;
    addition(fra_1, fra_2, result);
}

void multiplication(int *fra_1, int *fra_2, int *result){
    *(result+1) = *(fra_1+1) * *(fra_2+1);
    *(result+2) = *(fra_1+2) * *(fra_2+2);
}

void division(int *fra_1, int *fra_2, int *result){
    int substitution = *(fra_2+1);
    *(fra_2+1) = *(fra_2+2);
    *(fra_2+2) = substitution;
    multiplication(fra_1, fra_2, result);
}

void simply(int *fra){
    int gcd;
    find_greatest_common_divisor(fra+1, fra+2, &gcd);
    *(fra+1) /= gcd;
    *(fra+2) /= gcd;
    if(*(fra+2) < 0){
        *(fra+1) *= -1;
        *(fra+2) *= -1;
    }

    if(*(fra+1) > 0){
        if (*(fra+1) > *(fra+2)){
            *fra = *(fra+1) / *(fra+2);
            *(fra+1) %= *(fra+2);
        }else{*fra = 0;}
    }else{
        if (-*(fra+1) > *(fra+2)){
            *fra = *(fra+1) / *(fra+2);
            *(fra+1) = -*(fra+1) % *(fra+2);
        }else{
            *fra = 0;
        }
    }
}

int main(){
    char str_1[10], str_2[10];
    char operation, next;
    int fra_1[3], fra_2[3], result[3] = {0};

    while(1){
        scanf("%s %c %s", str_1, &operation, str_2);
        convert_to_numbers(str_1, fra_1);
        convert_to_numbers(str_2, fra_2);

        if ((fra_1[2] == 0) || (fra_2[2] == 0)){printf("Error\n");}
        else{
            if (operation == '+'){addition(fra_1, fra_2, result);}
            if (operation == '-'){subtraction(fra_1, fra_2, result);}
            if (operation == '*'){multiplication(fra_1, fra_2, result);}
            if (operation == '/'){division(fra_1, fra_2, result);}

            if (result[2] == 0){printf("Error\n");}
            else{
                simply(result);
                if (result[1] == 0){printf("%d\n", result[0]);}
                else if(*result == 0){printf("%d/%d\n", result[1], result[2]);}
                else{printf("%d(%d/%d)\n", result[0], result[1], result[2]);}
            }
        }
        scanf(" %c", &next);
        if (next == 'n'){break;}
    }
    return 0;
}
