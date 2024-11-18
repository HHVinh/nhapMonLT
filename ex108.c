#include <stdio.h>

// Hàm tính x^y bằng vòng lặp
double tinhMu(double x, int y) {
    double result = 1.0;

    // Nếu y là số âm, sẽ tính mũ của số âm
    if (y < 0) {
        x = 1 / x;  // Đảo ngược x
        y = -y;  // Chuyển y thành dương
    }

    // Dùng vòng lặp để tính x^y
    for (int i = 1; i <= y; i++) {
        result *= x;
    }

    return result;
}

int main() {
    double x;
    int y;

    // Nhập x và y
    printf("Nhập x: ");
    scanf("%lf", &x);
    printf("Nhập y: ");
    scanf("%d", &y);

    // Gọi hàm và in kết quả
    double result = tinhMu(x, y);
    printf("%.2f^%d = %.2f\n", x, y, result);

    return 0;
}
