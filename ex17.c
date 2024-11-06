#include <stdio.h>

int main() {
    int x, n;
    double ketQua = 0.0;
    printf("Hay nhap 2 so nguyen bat ki: ");
    scanf("%d %d", &x, &n);
    
    // Khởi tạo các biến
    double luyThua = 1.0; // luyThua cho x^i
    double mau = 1.0; // mau cho i!
    
    for (int i = 1; i <= n; i++) {
        luyThua *= x; // Tính x^i
        mau *= i;     // Tính i!
        ketQua += luyThua / mau; // Cộng thêm x^i / i! vào ketQua
        printf("Tong sau lan lap thu %d la: %6f\n", i, ketQua); // In ra tổng hiện tại
    }
    
    printf("Tong ket qua la: %6f\n", ketQua); // In ra tổng kết quả
    return 0;
}
