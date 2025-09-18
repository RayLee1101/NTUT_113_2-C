//
//  main.c
//  hw17
//
//  Created by RayLee on 2025/3/24.
//

#include <stdio.h>
struct item{
    int total;
    int win;
};

int main(int argc, const char * argv[]) {
    struct item AT[3] = {{0,0}, {0,0}, {0,0}};
    int number;
    scanf("%d", &number);
    for(int i = 0; i < number; i++){
        char item1, item2;
        int item1_num = 0, item2_num = 0;
        scanf(" %c %c", &item1, &item2);
        for (int j = 0 ; j < 4; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
            item1_num += a;
            item2_num += b;
        }
        if(item1 == 'A'){
            AT[0].total+=item1_num;
            if(item1_num > item2_num)
                AT[0].win++;
        }else if(item1 == 'B'){
            AT[1].total+=item1_num;
            if(item1_num > item2_num)
                AT[1].win++;
        }else{
            AT[2].total+=item1_num;
            if(item1_num > item2_num)
                AT[2].win++;
        }
        if(item2 == 'A'){
            AT[0].total+=item2_num;
            if(item1_num < item2_num)
                AT[0].win++;
        }else if(item2 == 'B'){
            AT[1].total+=item2_num;
            if(item1_num < item2_num)
                AT[1].win++;
        }else{
            AT[2].total+=item2_num;
            if(item1_num < item2_num)
                AT[2].win++;
        }
    }
    if(AT[0].win > AT[1].win && AT[0].win > AT[2].win){
        printf("A %d\n", AT[0].total);
    }else if(AT[1].win > AT[0].win && AT[1].win > AT[2].win){
        printf("B %d\n", AT[1].total);
    }else{
        printf("C %d\n", AT[2].total);
    }
    return 0;
}
