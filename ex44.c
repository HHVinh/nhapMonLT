#include <stdio.h>

int main() {
    int n, tong = 0;

    // Nhập số nguyên dương n
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện n phải là số nguyên dương
    if (n <= 0) {
        printf("Vui lòng nhập số nguyên dương.\n");
        return 0;
    }

    while (n > 0) {
        tong += n%10;
        n /= 10;
    }

    printf("Kết quả là: %d\n", tong);
    return 0;
}