#include <stdio.h>

int main() {
    int n, ketQua = 0, dem = 0;

    // Nhập số nguyên dương
    printf("Hãy nhập số bất kì: ");
    scanf("%d", &n);

    // Kiểm tra đầu vào
    if (n <= 0) {
        printf("Vui lòng nhập số nguyên dương!\n");
        return 1;
    }

    // Tìm chữ số lớn nhất và đếm số lần xuất hiện
    while (n > 0) {
        int chuSo = n % 10; // Lấy chữ số cuối

        if (chuSo == ketQua) {
            dem++; // Nếu bằng chữ số lớn nhất, tăng đếm
        } else if (chuSo > ketQua) {
            ketQua = chuSo; // Cập nhật chữ số lớn nhất
            dem = 1; // Đặt lại đếm vì chữ số lớn nhất mới xuất hiện
        }

        n /= 10; // Loại bỏ chữ số cuối
    }

    // In kết quả
    printf("Chữ số lớn nhất là: %d\n", ketQua);
    printf("Số lần xuất hiện: %d\n", dem);

    return 0;
}

