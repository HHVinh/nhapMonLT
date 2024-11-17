#include <stdio.h>
#include <math.h>

// Hàm kiểm tra tính hợp lệ của tam giác
int kiemTraTamGiac(float a, float b, float c) {
    // Kiểm tra điều kiện tam giác (tổng của hai cạnh phải lớn hơn cạnh còn lại)
    return (a + b > c && a + c > b && b + c > a);
}

// Hàm xác định loại tam giác
void xacDinhTamGiac(float a, float b, float c) {
    // Kiểm tra tính hợp lệ của tam giác
    if (!kiemTraTamGiac(a, b, c)) {
        printf("Đây không phải là tam giác hợp lệ.\n");
        return; // Không kiểm tra loại tam giác nếu không hợp lệ
    }

    // Kiểm tra tam giác đều
    if (a == b && b == c) {
        printf("Đây là tam giác đều.\n");
    }
    // Kiểm tra tam giác vuông cân
    else if ((a == b || b == c || a == c) && (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2))) {
        printf("Đây là tam giác vuông cân.\n");
    }
    // Kiểm tra tam giác vuông
    else if (pow(a, 2) + pow(b, 2) == pow(c, 2) || pow(a, 2) + pow(c, 2) == pow(b, 2) || pow(b, 2) + pow(c, 2) == pow(a, 2)) {
        printf("Đây là tam giác vuông.\n");
    }
    // Kiểm tra tam giác cân
    else if (a == b || b == c || a == c) {
        printf("Đây là tam giác cân.\n");
    }
    // Kiểm tra tam giác nhọn
    else if (pow(a, 2) + pow(b, 2) > pow(c, 2) && pow(a, 2) + pow(c, 2) > pow(b, 2) && pow(b, 2) + pow(c, 2) > pow(a, 2)) {
        printf("Đây là tam giác nhọn.\n");
    }
    // Kiểm tra tam giác tù
    else {
        printf("Đây là tam giác tù.\n");
    }
}

int main() {
    float a, b, c;

    // Nhập 3 cạnh của tam giác
    printf("Nhập ba cạnh của tam giác (a, b, c): ");
    scanf("%f %f %f", &a, &b, &c);

    // Xác định loại tam giác
    xacDinhTamGiac(a, b, c);

    return 0;
}
