#include <stdio.h>

int main() {
    float a, b, c, temp;

    // Nhập 3 số thực
    printf("Nhập ba số thực: ");
    scanf("%f %f %f", &a, &b, &c);

    // Sắp xếp các số theo thứ tự tăng dần
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = b;
        b = c;
        c = temp;
    }
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }

    // In ra các số theo thứ tự tăng dần
    printf("Ba số theo thứ tự tăng dần: %.2f, %.2f, %.2f\n", a, b, c);

    return 0;
}
