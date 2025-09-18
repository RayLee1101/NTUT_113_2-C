//
//  main.c
//  hw25
//
//  Created by RayLee on 2025/4/27.
//

#include <stdio.h>
#include <stdlib.h>

int sort(const void *a, const void *b){
    const int *val1 = (const int *)a;
    const int *val2 = (const int *)b;
    if(val1[1] == val2[1])
        return val1[0] - val2[0];
    return val2[1] - val1[1];
}

int max(int a, int b){
    return (a > b)? a: b;
}
int min(int a, int b){
    return (a < b)? a: b;
}

int check_around(int data[10][10], int x, int y, int mode){
    int num1 = 1, num2 = 1;
    if(mode == 1){
        if(x - 5 < 0 || y - 5 < 0) num1 = 0;
        else num1 = data[x - 5][y - 5];
        if(x + 1 > 9 || y + 1 > 9) num2 = 0;
        else num2 = data[x + 1][y + 1];
    }
    if(mode == 2){
        if(x - 5 < 0 || y + 5 > 9) num1 = 0;
        else num1 = data[x - 5][y + 5];
        if(x + 1 > 9 || y - 1 < 0) num2 = 0;
        else num2 = data[x + 1][y - 1];
    }
    if(mode == 3){
        if(x - 5 < 0) num1 = 0;
        else num1 = data[x - 5][y];
        if(x + 1 > 9) num2 = 0;
        else num2 = data[x + 1][y];
    }
    if(mode == 4){
        if(y - 5 < 0) num1 = 0;
        else num1 = data[x][y - 5];
        if(y + 1 > 9) num2 = 0;
        else num2 = data[x][y + 1];
    }
    return  (num1 + num2 > 0)?1: 0;
}

int check(int data[10][10], int x, int y){
    int n = 0, max_num = 0;
    data[x][y] = 1;
    for (int i = -4; i < 5; i++) {
        if(x + i > 9 || x + i < 0 || y + i > 9|| y + i < 0) continue;
        if(data[x + i][y + i] == 1){
            max_num++;
            if(max_num == 5){
                if(check_around(data, x + i, y + i, 1) == 0)
                    n++;
            }
        }else{
            max_num = 0;
        }
    }
//    if(max_num == 5) n++;
    
    max_num = 0;
    for (int i = -4; i < 5; i++) {
        if(x + i > 9 || x + i < 0 || y - i > 9|| y - i < 0) continue;
        if(data[x + i][y - i] == 1) {
            max_num++;
            if(max_num == 5){
                if(check_around(data, x + i, y - i, 2) == 0)
                    n++;
            }
        }else {
            max_num = 0;
        }
    }
//    if(max_num == 5) n++;
    
    max_num = 0;
    for (int i = -4; i < 5; i++) {
        if(x + i > 9 || x + i < 0) continue;
        if(data[x + i][y] == 1){
            max_num++;
            if(max_num == 5){
                if(check_around(data, x + i, y, 3) == 0)
                    n++;
            }
        }else {
            max_num = 0;
        }
    }
//    if(max_num == 5) n++;
    
    max_num = 0;
    for (int i = -4; i < 5; i++) {
        if(y + i > 9 || y + i < 0) continue;
        if(data[x][y + i] == 1){
            max_num++;
            if(max_num == 5)
                if(check_around(data, x, y + i, 4) == 0)
                    n++;
        }else {
            max_num = 0;
        }
    }
    
    data[x][y] = 0;
    
    return n;
}

int main(int argc, const char * argv[]) {
    int data[10][10] = {0};
    int result[99][2] = {0}, count = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            scanf("%d", &data[i][j]);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if(data[i][j] == 0){
                int n = check(data, i, j);
                if(n > 0){
                    result[count][0] = i * 10 + j;
                    result[count][1] = n;
                    count++;
                }
            }
        }
    }
    
    qsort(result, count, sizeof(result[0]), sort);
    
    for (int i = 0; i < count; i++) {
        if(result[i][0] < 10)
            printf("0%d %d\n", result[i][0], result[i][1]);
        else
            printf("%d %d\n", result[i][0], result[i][1]);
    }
    
    return 0;
}
