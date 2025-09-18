//
//  main.c
//  hw22
//
//  Created by RayLee on 2025/4/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(const void *a, const void *b){
    const int *val1 = (const int *)a;
    const int *val2 = (const int *)b;
    if(val1[0] == val2[0])
        return val1[1] - val2[1];
    return val1[0] - val2[0];
}

void draw(int ans[][2], int size, int x, int y, int *count){
    for(int m = 0; m < size; m++){
        for (int n = 0; n < size; n++){
            ans[*count][0] = x + m;
            ans[*count][1] = y + n;
            (*count)++;
        }
    }
}

void compute(int ans[][2], int *count, int x, int y, int size, int *position, char action[99]){
    for(int i = 0; i < 4; i++){
        if(action[*position] == '2'){
            (*position)++;
            if(i == 0)
                compute(ans, count, x, y, size / 2, position, action);
            else if(i == 1)
                compute(ans, count, x, y + size, size / 2, position, action);
            else if(i == 2)
                compute(ans, count, x + size, y, size / 2, position, action);
            else
                compute(ans, count, x + size, y + size, size / 2, position, action);
        }else if(action[*position] == '1'){
            if(i == 0)
                draw(ans, size, x, y , count);
            else if(i == 1)
                draw(ans, size, x, y + size , count);
            else if(i == 2)
                draw(ans, size, x + size, y , count);
            else
                draw(ans, size, x + size, y + size , count);
            (*position)++;
        }else{
            (*position)++;
        }
    }
}

int main(int argc, const char * argv[]) {
    char action[99] = {'\0'};
    int size = 0, count = 0, position= 0;
    int ans[99][2] = {0};
    scanf("%s", action);
    scanf("%d", &size);
    
    if(action[0] == '1'){
        for(int i = 0; i < size; i++)
            for(int j = 0; j < size; j++)
                printf("%d,%d\n", i, j);
        return 0;
    }else if(action[0] == '0'){
        printf("all white\n");
        return 0;
    }else{
        compute(ans, &count, 0, 0, size, &position, action);
    }
    
    qsort(ans, count, sizeof(ans[0]), sort);
    
    for(int i = 0; i < count; i++){
        printf("%d,%d\n", ans[i][0], ans[i][1]);
    }
    
    return 0;
}
