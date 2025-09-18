#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14

// 共用部分（模擬虛擬函數）
#define SHAPE_HEADER(TYPE) \
    char name[16]; \
    double (*perimeter)(struct TYPE*); \
    double (*area)(struct TYPE*)

// 各種圖形結構
typedef struct shape_s {
    SHAPE_HEADER(shape_s);
} shape_t;

typedef struct circle_s {
    SHAPE_HEADER(circle_s);
    double radius;
} circle_t;

typedef struct rectangle_s {
    SHAPE_HEADER(rectangle_s);
    double length, width;
} rectangle_t;

typedef struct square_s {
    SHAPE_HEADER(square_s);
    double edge;
} square_t;

typedef struct triangle_s {
    SHAPE_HEADER(triangle_s);
    double a, b, c;
} triangle_t;

// 周長與面積函數定義
double circle_perimeter(circle_t* c) {
    return 2 * PI * c->radius;
}
double circle_area(circle_t* c) {
    return PI * c->radius * c->radius;
}

double rectangle_perimeter(rectangle_t* r) {
    return 2 * (r->length + r->width);
}
double rectangle_area(rectangle_t* r) {
    return r->length * r->width;
}

double square_perimeter(square_t* s) {
    return 4 * s->edge;
}
double square_area(square_t* s) {
    return s->edge * s->edge;
}

double triangle_perimeter(triangle_t* t) {
    return t->a + t->b + t->c;
}
double triangle_area(triangle_t* t) {
    double p = (t->a + t->b + t->c) / 2.0;
    return sqrt(p * (p - t->a) * (p - t->b) * (p - t->c));
}

// 主程式
int main() {
    int N;
    scanf("%d", &N);

    shape_t* shapes[N];  // 儲存所有圖形的指標
    double total_perimeter = 0;
    double total_area = 0;

    for (int i = 0; i < N; ++i) {
        char type;
        scanf(" %c", &type);

        if (type == 'C') {
            circle_t* c = (circle_t*)malloc(sizeof(circle_t));
            scanf("%lf", &c->radius);
            strcpy(c->name, "Circle");
            c->perimeter = (double (*)(struct circle_s*))circle_perimeter;
            c->area = (double (*)(struct circle_s*))circle_area;
            shapes[i] = (shape_t*)c;

        } else if (type == 'R') {
            rectangle_t* r = (rectangle_t*)malloc(sizeof(rectangle_t));
            scanf("%lf %lf", &r->length, &r->width);
            strcpy(r->name, "Rectangle");
            r->perimeter = (double (*)(struct rectangle_s*))rectangle_perimeter;
            r->area = (double (*)(struct rectangle_s*))rectangle_area;
            shapes[i] = (shape_t*)r;

        } else if (type == 'S') {
            square_t* s = (square_t*)malloc(sizeof(square_t));
            scanf("%lf", &s->edge);
            strcpy(s->name, "Square");
            s->perimeter = (double (*)(struct square_s*))square_perimeter;
            s->area = (double (*)(struct square_s*))square_area;
            shapes[i] = (shape_t*)s;

        } else if (type == 'T') {
            triangle_t* t = (triangle_t*)malloc(sizeof(triangle_t));
            scanf("%lf %lf %lf", &t->a, &t->b, &t->c);
            strcpy(t->name, "Triangle");
            t->perimeter = (double (*)(struct triangle_s*))triangle_perimeter;
            t->area = (double (*)(struct triangle_s*))triangle_area;
            shapes[i] = (shape_t*)t;
        }
    }

    for (int i = 0; i < N; ++i) {
        double p = shapes[i]->perimeter(shapes[i]);
        double a = shapes[i]->area(shapes[i]);
        total_perimeter += p;
        total_area += a;
        printf("%.2f %.2f\n", p, a);
        free(shapes[i]); // 釋放記憶體
    }

    printf("%.2f %.2f\n", total_perimeter, total_area);

    return 0;
}
