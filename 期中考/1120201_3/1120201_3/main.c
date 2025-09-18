//
//  main.c
//  1120201_3
//
//  Created by RayLee on 2025/4/7.
//

#include <stdio.h>
#include <stdlib.h>

struct number{
    int id, run, fight;
};
int s_fun(const void *a, const void *b){
    struct number *A = (struct number *) a;
    struct number *B = (struct number *) b;
    return A->run - B -> run;
}

int main(int argc, const char * argv[]) {
    char data[9][99] = {'\0'};
    struct number numbers[9] = {0};
    int bag[3] = {-1, -1, -1};
    int out = 0, point = 0, end = 0, idx1 = 0, idx2 = 0;
    
    for(int i = 0; i < 9; i++){
        int num = 0;
        scanf("%d", &num);
        for(int j = 0; j < num; j++)
            scanf(" %c", &data[i][j]);
    }
    scanf("%d", &end);
    
    while(out < end){
        int n = 0;
        if(data[idx1][idx2] == 'O'){
            out++;
            if(out % 3 == 0) for(int i = 0; i < 3; i++) bag[i] = -1;
            if(out == end) printf("%d\n", point);
        }else if(data[idx1][idx2] == '1') n = 1;
        else if(data[idx1][idx2] == '2') n = 2;
        else if(data[idx1][idx2] == '3') n = 3;
        else n = 4;
        numbers[idx1].id = idx1;
        if(n > 0) numbers[idx1].fight++;
        for(int i = 0; i < n; i++){
            if(bag[2] != -1) point++;
            for(int j = 0; j < 3; j++)if(bag[j] != -1) numbers[bag[j]].run++;
            bag[2] = bag[1];
            bag[1] = bag[0];
            bag[0] = -1;
            if(i == 0){
                bag[0] = idx1;
                numbers[idx1].run++;
            }
        }
        if(idx1 == 8) idx2++;
        idx1 = (idx1 < 8)? idx1 + 1: 0;
    }
    qsort(numbers, sizeof(numbers) / sizeof(numbers[0]), sizeof(struct number), s_fun);
    for(int i = 0; i < 3; i++){
        printf("%d %d %d\n", numbers[i].id + 1, numbers[i].fight, numbers[i].run);
    }
    
    return 0;
}
