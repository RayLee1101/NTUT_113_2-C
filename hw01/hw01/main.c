#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int computeArea(int a, int b, int c) {
    int D = b * b - 4 * a * c;
    if(D < 0){
        int count = (-b) / (2 * a);
        int uncount = sqrt(abs(D)) / (2 * a);
        printf("%d+%di\n%d-%di\n", count, uncount, count, uncount);
    }else if(D == 0){
        int ans = (-b) / (2 * a);
        printf("%d\n", ans);
    }else{
        int ans1 = (-b + sqrt(D)) / (2 * a);
        int ans2 = (-b - sqrt(D)) / (2 * a);
        printf("%d\n%d\n", ans1, ans2);
    }
    return 0;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    computeArea(a, b, c);
    return 0;
}
