//
//  main.c
//  hw34
//
//  Created by RayLee on 2025/5/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 10
#define MAX_OPERATIONS 10

typedef struct {
    int machine;
    int time;
} Operation;

typedef struct {
    int num_ops;
    Operation ops[MAX_OPERATIONS];
} Job;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Job jobs[MAX_JOBS];
    int job_progress[MAX_JOBS] = {0};
    int job_completion[MAX_JOBS] = {0};
    int machine_available[10] = {0};
    int remaining_ops = 0;

    for (int i = 0; i < M; i++) {
        scanf("%d", &jobs[i].num_ops);
        remaining_ops += jobs[i].num_ops;
        for (int j = 0; j < jobs[i].num_ops; j++) {
            scanf("%d %d", &jobs[i].ops[j].machine, &jobs[i].ops[j].time);
        }
    }

    while (remaining_ops > 0) {
        int min_completion_time = 1e9;
        int selected_job = -1;
        int selected_op = -1;

        for (int i = 0; i < M; i++) {
            if (job_progress[i] < jobs[i].num_ops) {
                int j = job_progress[i];
                int machine = jobs[i].ops[j].machine;
                int time = jobs[i].ops[j].time;
                int prev_completion = (j > 0) ? job_completion[i] : 0;
                int start_time = machine_available[machine] > prev_completion ? machine_available[machine] : prev_completion;
                int completion_time = start_time + time;

                if (completion_time < min_completion_time || (completion_time == min_completion_time && i < selected_job)) {
                    min_completion_time = completion_time;
                    selected_job = i;
                    selected_op = j;
                }
            }
        }

        if (selected_job != -1) {
            int machine = jobs[selected_job].ops[selected_op].machine;
            int time = jobs[selected_job].ops[selected_op].time;
            int prev_completion = (selected_op > 0) ? job_completion[selected_job] : 0;
            int start_time = machine_available[machine] > prev_completion ? machine_available[machine] : prev_completion;
            int completion_time = start_time + time;

            machine_available[machine] = completion_time;
            job_completion[selected_job] = completion_time;
            job_progress[selected_job]++;
            remaining_ops--;
        }
    }

    int total_completion = 0;
    for (int i = 0; i < M; i++) {
        total_completion += job_completion[i];
    }

    printf("%d\n", total_completion);

    return 0;
}
