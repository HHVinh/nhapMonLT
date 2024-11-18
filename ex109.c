#include <stdio.h>

int bangCuuChuong(int a) {
    for (int i = 1; i <= 10; i++) {
        int ketQua = a * i;
        printf("    %d   x   %d   =   %d\n", a, i, ketQua);
    }
    return 0;
}

int main() {
    int n;

    printf("Nhập số từ 1 đến 9: ");
    scanf("%d", &n);

    // Kiểm tra nếu số không hợp lệ
    if (n < 1 || n > 9) {
        printf("Dữ liệu không hợp lệ!\n");
    } else {
        printf("=== Bảng cửu chương %d ===\n", n);
        bangCuuChuong(n);  // Gọi hàm in bảng cửu chương
    }

    return 0;
}
