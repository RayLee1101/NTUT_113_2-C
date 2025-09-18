//
//  main.c
//  hw20
//
//  Created by RayLee on 2025/4/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(const void *a, const void *b){
    const int *val1 = (const int *)a;
    const int *val2 = (const int *)b;
    return *val1 - *val2;
}

int main(int argc, const char * argv[]) {
    int data_test[3][4] = {
        {0,3,0,0},
        {5,1,2,6},
        {0,4,0,0},
    };
    int num = 0, data[4][3][4], d[4] = {1,1,1,1};
    memcpy(data[0],data_test, sizeof(data_test));
    memcpy(data[1],data_test, sizeof(data_test));
    memcpy(data[2],data_test, sizeof(data_test));
    memcpy(data[3],data_test, sizeof(data_test));
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        for(int j = 0; j < 4; j++){
            int act = 0;
            scanf("%d", &act);
            if(act == 1){
                data[j][1][1] = data[j][0][1];
                data[j][0][1] = data[j][1][3];
                data[j][1][3] = data[j][2][1];
                data[j][2][1] = d[j];
                d[j] = data[j][1][1];
            }else if(act == 2){
                data[j][1][1] = data[j][2][1];
                data[j][2][1] = data[j][1][3];
                data[j][1][3] = data[j][0][1];
                data[j][0][1] = d[j];
                d[j] = data[j][1][1];
            }else if(act == 3){
                data[j][1][1] = data[j][1][0];
                data[j][1][0] = data[j][1][3];
                data[j][1][3] = data[j][1][2];
                data[j][1][2] = d[j];
                d[j] = data[j][1][1];
            }else{
                data[j][1][1] = data[j][1][2];
                data[j][1][2] = data[j][1][3];
                data[j][1][3] = data[j][1][0];
                data[j][1][0] = d[j];
                d[j] = data[j][1][1];
            }
        }
    }
    
    qsort(d, 4, sizeof(d[0]), sort);
    if(d[0] == d[3]){
        printf("18\n");
    }else if(d[0] != d[1] && d[1] != d[2] && d[2] != d[3] || d[0] == d[1] && d[1] == d[2] || d[3] == d[1] && d[1] == d[2] ){
        printf("0\n");
    }else if(d[0] == d[1] && d[2] == d[3]){
        printf("%d\n", d[2] * 2);
    }else{
        int ans = 0;
        if(d[0] == d[1])
            ans = d[2] + d[3];
        else if(d[1] == d[2])
            ans = d[0] + d[3];
        else
            ans = d[0] + d[1];
        printf("%d\n", ans);
    }
    
    return 0;
}
