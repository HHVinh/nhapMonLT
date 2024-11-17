#include <stdio.h>
#include <math.h>

// Hàm giải phương trình bậc 2
void giaiPhuongTrinhBac2(float a, float b, float c) {
    // Tính delta
    float delta = b * b - 4 * a * c;

    // Kiểm tra delta
    if (delta > 0) {
        // Hai nghiệm phân biệt
        float x1 = (-b + sqrt(delta)) / (2 * a);
        float x2 = (-b - sqrt(delta)) / (2 * a);
        printf("Phuong trinh bac 2 co hai nghiem phan biet: x1 = %.2f, x2 = %.2f\n", x1, x2);
    } else if (delta == 0) {
        // Nghiệm kép
        float x = -b / (2 * a);
        printf("Phuong trinh bac 2 co nghiem kep: x = %.2f\n", x);
    } else {
        // Không có nghiệm thực
        printf("Phuong trinh bac 2 vo nghiem (delta < 0).\n");
    }
}

// Hàm giải phương trình bậc 1
void giaiPhuongTrinhBac1(float b, float c) {
    if (b == 0) {
        if (c == 0) {
            printf("Phuong trinh vo so nghiem.\n"); // Cả b và c đều bằng 0
        } else {
            printf("Phuong trinh vo nghiem.\n"); // Chỉ có c khác 0
        }
    } else {
        // Tính nghiệm của phương trình bậc 1
        float x = -c / b;
        printf("Phuong trinh bac 1 co nghiem: x = %.2f\n", x);
    }
}

int main() {
    float a, b, c;

    // Nhập các hệ số a, b, c của phương trình
    printf("Nhap cac he so a, b, c cua phuong trinh: ");
    scanf("%f %f %f", &a, &b, &c);

    // Kiểm tra nếu a == 0, giải phương trình bậc 1
    if (a == 0) {
        giaiPhuongTrinhBac1(b, c);
    } else {
        // Giải phương trình bậc 2
        giaiPhuongTrinhBac2(a, b, c);
    }

    return 0;
}
