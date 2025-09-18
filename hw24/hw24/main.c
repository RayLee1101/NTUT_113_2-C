//
//  main.c
//  hw24
//
//  Created by RayLee on 2025/4/13.
//
#include <stdio.h>

void init_block (int block[9][12], int x, int y, int color){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            block[x + i][y + j] = color;
        }
    }
}

void rotate(int block[9][12], int x, int y){
    int target[3][3];
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            target[i][j] = block[x + j][ y + 2 - i];
    for(int i = 0; i < 3; i ++)
        for(int j = 0; j < 3; j++)
            block[x + i][y + j] = target[i][j];
}

void rotate_column(int block[9][12], int num){
    for(int i = 0; i < 3; i++){
        int target = block[0][3 + num];
        for(int i = 0; i < 8; i++)
            block[i][3 + num] = block[i + 1][3 + num];
        block[8][3 + num] = target;
    }
    for(int i = 0; i < 3; i ++){
        int target = block[6 + i][3 + num];
        block[6 + i][3 + num] = block[5 - i][11 - num];
        block[5 - i][11 - num] = target;
    }
    if(num == 0){
        rotate(block, 3, 0);
    }else if(num == 2){
        for(int i = 0; i < 3; i++)
            rotate(block, 3, 6);
    }
}

void rotate_row(int block[9][12], int num){
    for(int j = 0; j < 3; j++){
        int target = block[3 + num][0];
        for(int i = 0; i < 11; i++)
            block[3 + num][i] = block[3 + num][i + 1];
        block[3 + num][11] = target;
    }
    if(num == 2){
        rotate(block, 6, 3);
    }else if(num == 0){
        for(int i = 0; i < 3; i++)
            rotate(block, 0, 3);
    }
}

int main(int argc, const char * argv[]){
    int magic_block[9][12] = {0};
    init_block(magic_block,0, 3, 1);
    init_block(magic_block,3, 6, 2);
    init_block(magic_block,3, 9, 3);
    init_block(magic_block,3, 3, 4);
    init_block(magic_block,3, 0, 5);
    init_block(magic_block,6, 3, 6);
    int num = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int action = 0;
        scanf("%d", &action);
        if(action / 10 == 2)
            rotate_row(magic_block, action % 10);
        else
            rotate_column(magic_block, action % 10);
    }

    for (int i = 3; i < 6; i++)
    {
        for(int j = 3; j < 6; j++)
            printf("%d ", magic_block[i][j]);
        printf("\n");
    }
    
    return 0;
}

