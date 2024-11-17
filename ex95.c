#include <stdio.h>

// Hàm thay đổi các số âm thành trị tuyệt đối
void soThuc(float *a, float *b, float *c) {
    if (*a < 0) {
        *a = *a * -1.0;
    }
    if (*b < 0) {
        *b = *b * -1.0;
    }
    if (*c < 0) {
        *c = *c * -1.0;
    }
}

int main() {
    float a, b, c;

    // Nhập 3 số thực
    printf("Nhập 3 số thực: ");
    scanf("%f %f %f", &a, &b, &c);

    // Gọi hàm thay đổi trị tuyệt đối
    soThuc(&a, &b, &c);

    // In kết quả
    printf("Kết quả là: %f, %f, %f\n", a, b, c);

    return 0;
}
