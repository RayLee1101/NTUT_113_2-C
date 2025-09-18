//
//  main.c
//  hw26
//
//  Created by RayLee on 2025/5/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

int N;
int map[MAX][MAX], backup[MAX][MAX];
int best_path[MAX], temp_path[MAX];
int best_count =99999999;
int C,u, v;
void dfs(int depth, int current, int graph[MAX][MAX], int path[], int used[],int count) {
    if (depth == N) {
        if(best_count>count){

            best_count=count;
            memcpy(best_path, path, sizeof(int) * N);
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            if (graph[current][i] != -1) {
                int localGraph[MAX][MAX];
                memcpy(localGraph, graph, sizeof(localGraph));
                used[i] = 1;
                path[depth] = i + 1;
                count += graph[current][i];
                dfs(depth + 1, i, localGraph, path, used,count);
                used[i] = 0;
                count -= graph[current][i];
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    // 讀入圖
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);

    memcpy(backup, map, sizeof(map));

    scanf("%d", &C);
    scanf("%d %d", &u, &v);
    u--; v--;

    int used[MAX] = {0};
    int path[MAX] = {0};
    path[0] = 1;
    used[0] = 1;
    dfs(1, 0, map, path, used,0);
    map[u][v]= -1;
    int temp =0;
    for (int i = 0; i < N-1; i++){
        int a=best_path[i];
        int b=best_path[i+1];
        path[i]=a;
        used[a-1] = 1;
        if((a-1)==u&&v==(b-1)&&i+1>=C){
            best_count= 99999999;
            dfs(i+1, a-1, map, path, used,temp);
        }
        else{
            temp+=map[a-1][b-1];
        }
    }

    for (int i = 0; i < N; i++)
        printf("%d%c", best_path[i], i == N - 1 ? '\n' : ' ');
    printf("%d\n", best_count);

    return 0;
}
