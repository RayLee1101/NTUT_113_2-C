//
//  main.c
//  hw20
//
//  Created by RayLee on 2025/4/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun1(int data[3][4]){
    int target = data[1][1];
    data[1][1] = data[0][1];
    data[0][1] = data[1][3];
    data[1][3] = data[2][1];
    data[2][1] = target;
}

void fun2(int data[3][4]){
    int target = data[1][1];
    data[1][1] = data[1][0];
    data[1][0] = data[1][3];
    data[1][3] = data[1][2];
    data[1][2] = target;
}

int sort(const void *a, const void *b){
    const int *val1 = (const int *)a;
    const int *val2 = (const int *)b;
    return *val1 - *val2;
}

int main(int argc, const char * argv[]) {
    int data_target[3][4] = {
        {0,3,0,0},
        {5,1,2,6},
        {0,4,0,0}
    };
    int data[4][3][4], number = 0;
    for(int i = 0; i < 4; i++)
        memcpy(data[i], data_target, sizeof(int[3][4]));
    scanf("%d", &number);
    for(int i = 0; i < number; i++){
        int act[4] = {0,0,0,0};
        scanf("%d %d %d %d", &act[0], &act[1], &act[2], &act[3]);
        for(int j = 0; j < 4; j++){
            if(act[j] == 1)
                fun1(data[j]);
            else if(act[j] == 2)
                for(int m = 0; m < 3; m++)
                    fun1(data[j]);
            else if(act[j] == 3)
                fun2(data[j]);
            else
                for(int m = 0; m < 3; m++)
                    fun2(data[j]);
        }
    }
    
    int point[4] = {data[0][1][1], data[1][1][1], data[2][1][1], data[3][1][1]};
    qsort(point, 4, sizeof(point[0]), sort);
    
    if(point[0] == point[3])
        printf("18\n");
    else if((point[0] != point[1] && point[1] != point[2] && point[2] != point[3]) || (point[0] == point[2] )|| (point[1] == point[3])){
        printf("0\n");
    }else if(point[0] == point[1] && point[2] == point[3])
        printf("%d\n", point[2] * 2);
    else{
        if(point[0] == point[1])
            printf("%d\n", point[2] + point[3]);
        else if(point[1] == point[2])
            printf("%d\n", point[0] + point[3]);
        else
            printf("%d\n", point[0] + point[1]);
    }
    return 0;
}
