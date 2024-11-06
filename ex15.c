#include <stdio.h>

int main() {
    int n;
    double ketQua = 0.0; // Khởi tạo biến tổng
    printf("Hay nhap so nguyen n: ");
    scanf("%d", &n); // Loại bỏ khoảng trắng

    int mau = 0; // Khởi tạo biến mau
    for (int i = 1; i <= n; i++) {
        mau += i; // Cộng dồn từ 1 đến i
        ketQua += 1.0 / mau; // Cộng 1/mau vào ketQua
        printf("Tong sau lan lap thu %d la: %f\n", i, ketQua);
    }
    
    printf("Tong ket qua la: %f\n", ketQua); // In ra tổng kết quả
    return 0;
}
