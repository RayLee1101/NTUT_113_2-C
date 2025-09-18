#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 110

typedef struct {
    int duration;
    int out_degree;
    int out_nodes[MAXN];
    int in_degree;
    int max_time;
} TaskNode;

TaskNode nodes[MAXN];

int queue[MAXN], front, rear;

int max(int a, int b) {
    return a > b ? a : b;
}

int process_project(int m) {
    front = rear = 0;
    for (int i = 1; i <= m; i++) {
        if (nodes[i].in_degree == 0) {
            nodes[i].max_time = nodes[i].duration;
            queue[rear++] = i;
        }
    }

    int ans = 0;

    while (front < rear) {
        int now = queue[front++];
        if (nodes[now].max_time > ans) {
            ans = nodes[now].max_time;
        }

        for (int i = 0; i < nodes[now].out_degree; i++) {
            int next = nodes[now].out_nodes[i];
            nodes[next].in_degree--;
            if (nodes[next].max_time < nodes[now].max_time + nodes[next].duration) {
                nodes[next].max_time = nodes[now].max_time + nodes[next].duration;
            }
            if (nodes[next].in_degree == 0) {
                queue[rear++] = next;
            }
        }
    }

    return ans;
}

int main() {
    int N;
    scanf("%d", &N); // 專案數量

    for (int proj = 0; proj < N; proj++) {
        int m;
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            nodes[i].out_degree = 0;
            nodes[i].in_degree = 0;
            nodes[i].max_time = 0;
        }
        for (int i = 1; i <= m; i++) {
            int k;
            scanf("%d%d", &nodes[i].duration, &k);
            for (int j = 0; j < k; j++) {
                int target;
                scanf("%d", &target);
                nodes[i].out_nodes[nodes[i].out_degree++] = target;
                nodes[target].in_degree++;
            }
        }
        printf("%d\n", process_project(m));
    }

    return 0;
}
