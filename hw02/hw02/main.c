//
//  main.c
//  wh02
//
//  Created by RayLee on 2025/2/27.
//

#include <stdio.h>

int main() {
    int hits[5];
    int bases[3] = {0};
    int score = 0;
    int outs = 0;
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &hits[i]);
    }
    
    for (int i = 0; i < 5; i++) {
        if (hits[i] == 0) {
            outs++;
            if (outs == 3) {
                bases[0] = bases[1] = bases[2] = 0;
            }
            continue;
        }
        for (int j = 2; j >= 0; j--) {
            if (bases[j]) {
                int new_position = j + hits[i];
                if (new_position >= 3) {
                    score++;
                } else {
                    bases[new_position] = 1;
                }
                bases[j] = 0;
            }
        }
        if (hits[i] >= 4) {
            score++;
        } else {
            bases[hits[i] - 1] = 1;
        }
    }
    printf("%d\n", score);
    printf("%d %d %d\n", bases[0], bases[1], bases[2]);
    
    return 0;
}
