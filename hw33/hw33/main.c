//
//  main.c
//  hw33
//
//  Created by RayLee on 2025/5/25.
//

#include <stdio.h>
#include <string.h>

#define GATEVALUE(Gate) int(*GateValue)(struct _Gate*)

typedef struct _Gate {
    int input1;
    int input2;
    GATEVALUE(Gate);
} Gate;

// 各邏輯閘實作
int GateANDValue(Gate* gate) {
    return (gate->input1 & gate->input2) & 0x7;
}
int GateORValue(Gate* gate) {
    return (gate->input1 | gate->input2) & 0x7;
}
int GateNOTValue(Gate* gate) {
    return (~gate->input1) & 0x7;
}
int GateBUFFERValue(Gate* gate) {
    return gate->input1 & 0x7;
}
int GateNANDValue(Gate* gate) {
    return (~(gate->input1 & gate->input2)) & 0x7;
}
int GateNORValue(Gate* gate) {
    return (~(gate->input1 | gate->input2)) & 0x7;
}

// 建立閘門
void CreateGate(Gate* obj, char* type, int input1, int input2) {
    obj->input1 = input1 & 0x7;
    obj->input2 = input2 & 0x7;

    if (strcmp(type, "A") == 0)
        obj->GateValue = GateANDValue;
    else if (strcmp(type, "O") == 0)
        obj->GateValue = GateORValue;
    else if (strcmp(type, "N") == 0)
        obj->GateValue = GateNOTValue;
    else if (strcmp(type, "B") == 0)
        obj->GateValue = GateBUFFERValue;
    else if (strcmp(type, "NA") == 0)
        obj->GateValue = GateNANDValue;
    else if (strcmp(type, "NO") == 0)
        obj->GateValue = GateNORValue;
    else {
        printf("Unsupported gate type: %s\n", type);
        obj->GateValue = NULL;
    }
}

int main() {
    int X1, X2, X3;
    char t1[3], t2[3], t3[3], g1[3], g2[3];

    // 輸入
    scanf("%d %d %d", &X1, &X2, &X3);
    scanf("%s %s %s %s %s", t1, t2, t3, g1, g2);

    // Gate 定義
    Gate gx1, gx2, gx3, gy, gout;

    // 前處理 X1~X3
    CreateGate(&gx1, t1, X1, 0);
    int x1p = gx1.GateValue(&gx1);

    CreateGate(&gx2, t2, X2, 0);
    int x2p = gx2.GateValue(&gx2);

    CreateGate(&gx3, t3, X3, 0);
    int x3p = gx3.GateValue(&gx3);

    // 第一組閘 Y = x1p g1 x2p
    CreateGate(&gy, g1, x1p, x2p);
    int Y = gy.GateValue(&gy);

    // 第二組閘 Output = Y g2 x3p
    CreateGate(&gout, g2, Y, x3p);
    int Output = gout.GateValue(&gout);

    // 以三位元二進位格式輸出
    printf("%d%d%d\n", (Output >> 2) & 1, (Output >> 1) & 1, Output & 1);

    return 0;
}

