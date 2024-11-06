#include <stdio.h>
#include <math.h>

int main() {
    int x, n, mau = 0;
    double ketQua = 0.0;
    printf("Hay nhap 2 so nguyen bat ki: ");
    scanf("%d %d", &x, &n);
    int luyThua = 1;
    for (int i = 1; i <= n; i++) {
        mau += i;              // Tính tổng 1 + 2 + ... + i
        luyThua *= x;         // Tính x^i
        ketQua += (double) luyThua / mau; // Cộng thêm x^i / mau vào ketQua
        printf("Tong sau lan lap thu %d la: %6f\n", i, ketQua); // In ra tổng hiện tại
    }
    
    printf("Tong ket qua la: %6f\n", ketQua); // In ra tổng kết quả
    return 0;
}