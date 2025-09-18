//
//  main.c
//  hw17
//
//  Created by RayLee on 2025/4/15.
//

#include <stdio.h>

int which_item(char c){
    if(c == 'A')
        return 0;
    else if(c == 'B')
        return 1;
    else
        return 2;
}

int main(int argc, const char * argv[]) {
    int data[3][2] = {0}, game_count;
    scanf("%d", &game_count);
    for(int i = 0; i < game_count; i++){
        int item_A = 0, item_B = 0, total_A = 0, total_B = 0;
        char item = '\0';
        scanf(" %c", &item);
        item_A = which_item(item);
        scanf(" %c", &item);
        item_B = which_item(item);
        
        for(int j = 0; j < 4; j++){
            int a = 0, b = 0;
            scanf("%d %d", &a, &b);
            total_A += a;
            total_B += b;
        }
        data[item_A][0] += total_A;
        data[item_B][0] += total_B;
        if(total_A > total_B)
            data[item_A][1] += 1;
        else
            data[item_B][1] += 1;
    }
    if(data[0][1] > data[1][1] && data[0][1] > data[2][1])
        printf("A %d\n", data[0][0]);
    else if(data[1][1] > data[0][1] && data[1][1] > data[2][1])
        printf("B %d\n", data[1][0]);
    else
        printf("C %d\n", data[2][0]);
    
    return 0;
}
