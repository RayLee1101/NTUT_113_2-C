//
//  main.c
//  hw23
//
//  Created by RayLee on 2025/4/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort(const void *a, const void *b){
//    const char *str1 = (const char *)a;
//    const char *str2 = (const char *)b;
//    return strcmp(str1, str2);
    const int *str1 = (const int *)a;
    const int *str2 = (const int *)b;
    if (str1[0] == str2[0]) {
            return str1[1] - str2[1];
        }
    return str1[0] - str2[0];
}

int repeat (int com[][2], int count, int a, int b){
    for(int i = 0; i < count; i++){
        if(com[i][0] == a && com[i][1] == b)
            return 0;
    }
    return 1;
}

void combination(int com[][2], int *arr, int len, int *count){
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            if(arr[i] > arr[j]){
                if(repeat(com, *count, arr[i], arr[j])){
                    com[(*count)][0] = arr[i];
                    com[(*count)++][1] = arr[j];
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int num = 0, count = 0;
    scanf("%d", &num);
    int *arr = malloc(num * sizeof(int));
    for(int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    int com_arr[300][2];
    
    combination(com_arr, arr, num, &count);
    qsort(com_arr, count, sizeof(com_arr[0]), sort);
    
    if(count == 0) printf("0\n");
    for(int i = 0; i < count; i++){
        printf("(%d,%d)\n", com_arr[i][0], com_arr[i][1]);
    }
    
    return 0;
}
