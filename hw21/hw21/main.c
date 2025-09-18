//
//  main.c
//  hw21
//
//  Created by RayLee on 2025/4/13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SelectSort (int *arr, int len, int *compare, int *move){
    for(int i = 0; i < len; i++){
        int x = i;
        for(int j = i + 1; j < len; j++){
            *compare += 1;
            if(arr[x] > arr[j]){
                x = j;
            }
        }
        if(x != i){
            int target = arr[x];
            arr[x] = arr[i];
            arr[i] = target;
            *move += 3;
        }
    }
}
void InsertSort (int *arr, int len, int *compare, int *move){
    for (int i = 1; i < len; i++) {
        int target = arr[i];
        *move += 1;
        int j = i;

        while (j > 0) {
            *compare += 2;
            if (arr[j - 1] > target) {
                arr[j] = arr[j - 1];
                *move += 1;
                j--;
            } else {
                break;
            }
        }
        if(j <= 0) *compare += 1;
        arr[j] = target;
        *move += 1;
    }
}

int main(int argc, const char * argv[]) {
    int num = 0, compare = 0, move = 0;
    scanf("%d", &num);
    int *arr = malloc(num * sizeof(int));
    int *arrcopy = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
        scanf("%d", &arr[i]);
    
    memcpy(arrcopy, arr, num * sizeof(int));
    SelectSort(arrcopy, num, &compare, &move);
    printf("%d %d\n", compare, move);
    
    compare = 0; move = 0;
    memcpy(arrcopy, arr, num * sizeof(int));
    InsertSort(arrcopy, num, &compare, &move);
    printf("%d %d\n", compare, move);
    return 0;
}
