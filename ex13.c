#include <stdio.h>

int main() {
    int x, n, ketQua = 0;
    printf("Hay nhap 2 so x va n: ");
    scanf("%d %d", &x, &n);

    int luyThua = x * x;  // Khởi tạo luyThua = x^2 vì chúng ta bắt đầu từ x^2
    for (int i = 1; i <= n; i++) {
        ketQua += luyThua;  // Cộng lũy thừa hiện tại vào tổng
        luyThua *= x * x;   // Nhân tiếp với x^2 để đạt x^(2(i+1))
    }

    printf("Tong S(n) = %d\n", ketQua);
    return 0;
}
