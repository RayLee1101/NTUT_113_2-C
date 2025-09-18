//
//  main.c
//  hw22
//
//  Created by RayLee on 2025/4/13.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int sort(const void *a, const void *b){
    const int *val1 = (const int *)a;
    const int *val2 = (const int *)b;
    if(val1[0] == val2[0])
        return val1[1] - val2[1];
    return val1[0] - val2[0];
}

void draw(int ans[][2], int x, int y, int size, int *count){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            ans[*count][0] = i + x;
            ans[*count][1] = j + y;
            (*count)++;
        }
    }
}

void compute(char df[99], int ans[][2], int size, int *count, int *position, int x, int y){
    for(int i = 0; i < 4; i++){
        if(df[*position] == '1'){
            if(i == 0)
                draw(ans, x, y, size, count);
            else if(i == 1)
                draw(ans, x	, y + size , size, count);
            else if(i == 2)
                draw(ans, x + size, y, size, count);
            else
                draw(ans, x + size, y + size, size, count);
            *position += 1;
        }else if(df[*position] == '2'){
            *position += 1;
            if(i == 0)
                compute(df, ans, size / 2, count, position, x, y);
            else if(i == 1)
                compute(df, ans, size / 2, count, position, x, y + size);
            else if(i == 2)
                compute(df, ans, size / 2, count, position, x + size, y);
            else
                compute(df, ans, size / 2, count, position, x + size, y + size);
        }else{
            *position += 1;
        }
    }
}

int main(int argc, const char * argv[]) {
    char df[99] = {'\0'};
    scanf("%s", df);
    int size = 0, count = 0, position = 0;
    scanf("%d", &size);
    int ans[99][2];
    if(df[0] == '2')
        compute(df, ans, size, &count, &position, 0, 0);
    else if(df[0] == '1')
        draw(ans, 0, 0, size, &count);
    else
        printf("all white\n");
    qsort(ans, count, sizeof(ans[0]) , sort);
    
    for(int i = 0; i < count; i++){
        printf("%d,%d\n", ans[i][0], ans[i][1]);
    }
    return 0;
}
