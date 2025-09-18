//
//  main.c
//  hw29
//
//  Created by RayLee on 2025/5/11.
//

#include <stdio.h>
#include <math.h>

double a_global; // global 係數 a

// f1(x) = a * x^2
double f1(double x) {
    return a_global * x * x;
}

// f2(x) = a * x^3 + 1
double f2(double x) {
    return a_global * x * x * x + 1;
}

// 梯形法積分計算
double trapezoidal(double (*f)(double), double p, double q, int err) {
    int n = 1;
    double h, sum_prev = 0.0, sum_new = 0.0;
    double precision = pow(10, -err);

    while (1) {
        h = (q - p) / n;
        sum_new = 0.0;

        for (int i = 0; i <= n; i++) {
            double x = p + i * h;
            if (i == 0 || i == n) {
                sum_new += f(x);
            } else {
                sum_new += 2 * f(x);
            }
        }

        sum_new *= h / 2.0;

        if (n > 1 && fabs(sum_new - sum_prev) < precision) {
            break;
        }

        sum_prev = sum_new;
        n *= 2;
    }

    return sum_new;
}

int main() {
    int type;
    while (scanf("%d", &type) == 1) {
        if (type == 0) break;

        double a, p, q;
        int err;
        if (scanf("%lf %lf %lf %d", &a, &p, &q, &err) != 4) {
            break;
        }

        a_global = a;

        if (type == 1) {
            double result = trapezoidal(f1, p, q, err);
            printf("%.12lf\n", result);
        } else if (type == 2) {
            double result = trapezoidal(f2, p, q, err);
            printf("%.12lf\n", result);
        } else {
            printf("Invalid\n");
        }
    }
    return 0;
}
