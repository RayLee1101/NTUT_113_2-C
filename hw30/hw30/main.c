//
//  main.c
//  hw30
//
//  Created by RayLee on 2025/5/18.
//

#include <stdio.h>
#include <string.h>

typedef enum { OUT, BASE_HIT } play_type_t;

typedef union {
    int base_hit; // 1~4: number of bases
    char out_kind; // 'F', 'S', 'G'
} play_result_t;

typedef struct {
    play_type_t type;
    play_result_t result;
} play_t;

typedef struct {
    int no;
    play_t data[5];
} basePlayer_t;

void parse_play(char *str, play_t *play) {
    if (strcmp(str, "1B") == 0) {
        play->type = BASE_HIT;
        play->result.base_hit = 1;
    } else if (strcmp(str, "2B") == 0) {
        play->type = BASE_HIT;
        play->result.base_hit = 2;
    } else if (strcmp(str, "3B") == 0) {
        play->type = BASE_HIT;
        play->result.base_hit = 3;
    } else if (strcmp(str, "HR") == 0) {
        play->type = BASE_HIT;
        play->result.base_hit = 4;
    } else if (strcmp(str, "FO") == 0) {
        play->type = OUT;
        play->result.out_kind = 'F';
    } else if (strcmp(str, "GO") == 0) {
        play->type = OUT;
        play->result.out_kind = 'G';
    } else if (strcmp(str, "SO") == 0) {
        play->type = OUT;
        play->result.out_kind = 'S';
    }
}

int main() {
    basePlayer_t players[9];
    int target_outs;
    
    for (int i = 0; i < 9; i++) {
        scanf("%d", &players[i].no);
        char str[3];
        for (int j = 0; j < players[i].no; j++) {
            scanf("%s", str);
            parse_play(str, &players[i].data[j]);
        }
    }
    
    scanf("%d", &target_outs);
    
    int bases[4] = {0};
    int score = 0;
    int outs = 0;
    int total_outs = 0;
    int current_player = 0;
    int play_index[9] = {0};
    
    while (total_outs < target_outs) {
        basePlayer_t *player = &players[current_player];
        if (play_index[current_player] >= player->no) {
            current_player = (current_player + 1) % 9;
            continue;
        }
        play_t *play = &player->data[play_index[current_player]];
        play_index[current_player]++;
        
        if (play->type == BASE_HIT) {
            bases[0] = 1;
            int bases_to_advance = play->result.base_hit;
            
            for (int i = 3; i >= 0; i--) {
                if (bases[i] == 1) {
                    bases[i] = 0;
                    int new_base = i + bases_to_advance;
                    if (new_base >= 4) {
                        score++;
                    } else {
                        bases[new_base] = 1;
                    }
                }
            }
            bases[0] = 0;
        } else {
            total_outs++;
            outs++;
            if (total_outs >= target_outs) {
                break;
            }
            if (outs == 3) {
                bases[1] = bases[2] = bases[3] = 0;
                outs = 0;
            }
        }
        current_player = (current_player + 1) % 9;
    }
    
    printf("%d\n", score);
    
    return 0;
}
