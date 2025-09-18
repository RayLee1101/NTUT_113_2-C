//
//  main.c
//  hw05
//
//  Created by RayLee on 2025/3/7.
//

#include <stdio.h>
#include <math.h>

// 定義資費結構
typedef struct {
    int base_fee;           // 月租費
    int free_in_sec;        // 網內免費秒數
    int free_out_sec;       // 網外免費秒數
    int free_local_sec;     // 市話免費秒數
    int free_in_sms;        // 網內免費簡訊數
    int free_out_sms;       // 網外免費簡訊數
    double rate_in_sec;     // 網內語音費率
    double rate_out_sec;    // 網外語音費率
    double rate_local_sec;  // 市話費率
    double rate_in_sms;     // 網內簡訊費率
    double rate_out_sms;    // 網外簡訊費率
} Plan;

// 計算某個資費方案的總費用
double calculate_cost(Plan plan, int in_sec, int out_sec, int local_sec, int in_sms, int out_sms) {
    double total_cost = 0.0;

    // 計算網內語音費用
    if (in_sec > plan.free_in_sec) {
        total_cost += (in_sec - plan.free_in_sec) * plan.rate_in_sec;
    }

    // 計算網外語音費用
    if (out_sec > plan.free_out_sec) {
        total_cost += (out_sec - plan.free_out_sec) * plan.rate_out_sec;
    }

    // 計算市話費用
    if (local_sec > plan.free_local_sec) {
        total_cost += (local_sec - plan.free_local_sec) * plan.rate_local_sec;
    }

    // 計算網內簡訊費用
    if (in_sms > plan.free_in_sms) {
        total_cost += (in_sms - plan.free_in_sms) * plan.rate_in_sms;
    }

    // 計算網外簡訊費用
    if (out_sms > plan.free_out_sms) {
        total_cost += (out_sms - plan.free_out_sms) * plan.rate_out_sms;
    }

    // 月租費可抵通信費，若總通信費低於月租費，則以月租費計
    if (total_cost < plan.base_fee) {
        total_cost = plan.base_fee;
    }

    return total_cost;
}

int main() {
    // 定義三種資費方案
    Plan plans[3] = {
        {183, 500, 400, 300, 10, 15, 0.08, 0.1393, 0.1349, 1.1287, 1.4803}, // 183型
        {383, 600, 500, 400, 20, 25, 0.07, 0.1304, 0.1217, 1.1127, 1.2458}, // 383型
        {983, 700, 600, 500, 30, 35, 0.06, 0.1087, 0.1018, 0.9572, 1.1243}  // 983型
    };

    // 輸入資料
    int in_sec, out_sec, local_sec, in_sms, out_sms;
    scanf("%d %d %d %d %d", &in_sec, &out_sec, &local_sec, &in_sms, &out_sms);

    // 計算每種資費的費用
    double costs[3];
    for (int i = 0; i < 3; i++) {
        costs[i] = calculate_cost(plans[i], in_sec, out_sec, local_sec, in_sms, out_sms);
    }

    // 找出最低費用及其對應的資費類型
    double min_cost = costs[0];
    int min_plan = 0;
    for (int i = 1; i < 3; i++) {
        if (costs[i] < min_cost) {
            min_cost = costs[i];
            min_plan = i;
        }
    }

    // 輸出結果
    printf("%d\n", (int)floor(min_cost));  // 無條件捨去至整數
    printf("%d\n", plans[min_plan].base_fee);  // 最佳資費類型

    return 0;
}
