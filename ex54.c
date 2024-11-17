#include <stdio.h>

int main() {
    int n, ketQua = 10, dem = 0;

    // Nhập số nguyên dương
    printf("Hãy nhập số bất kì: ");
    scanf("%d", &n);

    // Kiểm tra đầu vào
    if (n <= 0) {
        printf("Vui lòng nhập số nguyên dương!\n");
        return 1;
    }

    // Xử lý từng chữ số trong số nguyên n
    while (n > 0) {
        int digit = n % 10; // Lấy chữ số cuối của n
        if (digit == ketQua) {
            dem++; // Nếu chữ số này bằng chữ số nhỏ nhất, tăng đếm
        } else if (digit < ketQua) {
            ketQua = digit; // Cập nhật chữ số nhỏ nhất
            dem = 1; // Đặt lại đếm vì đã tìm được chữ số nhỏ nhất mới
        }
        n /= 10; // Loại bỏ chữ số cuối
    }

    // In kết quả
    printf("Chữ số nhỏ nhất là: %d\n", ketQua);
    printf("Số lần xuất hiện: %d\n", dem);

    return 0;
}
