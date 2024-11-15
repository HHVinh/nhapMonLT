#include <stdio.h>

int main() {
    int n, dem = 0;

    // Nhập số nguyên dương n
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Kiểm tra điều kiện n phải là số nguyên dương
    if (n <= 0) {
        printf("Vui lòng nhập số nguyên dương.\n");
        return 0;
    }

    // Đếm số chữ số
    while (n > 0) {
        n /= 10;  // Loại bỏ chữ số cuối
        dem++;    // Tăng biến đếm
    }

    printf("Kết quả là: %d\n", dem);
    return 0;
}
