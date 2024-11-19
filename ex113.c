#include <stdio.h>
#include <math.h>

// Hàm tính giai thừa
long long tinhGiaiThua(int n) {
    long long ketQua = 1;
    for (int i = 1; i <= n; i++) {
        ketQua *= i;
    }
    return ketQua;
}

// Hàm tính sin(x) với độ chính xác 0.00001
double tinhSin(double x) {
    double sinX = 0; // Giá trị sin(x) ban đầu
    double term = x; // Số hạng đầu tiên của chuỗi (x)
    int n = 0;       // Số hạng thứ n

    while (fabs(term) >= 0.00001) {
        sinX += term; // Cộng/trừ số hạng vào kết quả
        n++;          // Chuyển sang số hạng tiếp theo
        term = pow(-1, n) * pow(x, 2 * n + 1) / tinhGiaiThua(2 * n + 1);
    }

    return sinX;
}

int main() {
    double x;
    printf("Nhập giá trị x (radian): ");
    scanf("%lf", &x);

    double ketQua = tinhSin(x);
    printf("Giá trị sin(%.5f) = %.5f\n", x, ketQua);

    return 0;
}
