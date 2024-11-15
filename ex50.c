#include <stdio.h>

int main() {
    int n, daoNguoc = 0;

    // Nhập số nguyên dương n
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Tính số đảo ngược của n
    while (n > 0) {
        daoNguoc = daoNguoc * 10 + (n % 10);  // Lấy chữ số cuối và thêm vào số đảo ngược
        n /= 10;  // Bỏ chữ số cuối
    }

    // In ra kết quả
    printf("Số đảo ngược của n là: %d\n", daoNguoc);
    return 0;
}
