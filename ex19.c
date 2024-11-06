#include <stdio.h>
#include <math.h>

// Hàm tính giai thừa của số k
int giaiThua(int k) {
    int ketQua = 1;
    for (int i = 1; i <= k; i++) {
        ketQua *= i; // Nhân dần dần để tính giai thừa
    }
    return ketQua; // Trả về kết quả giai thừa
}

int main() {
    int x, n;
    double ketQua = 1.0;  // Bắt đầu từ 1 vì S(0) = 1
    printf("Hay nhap 2 so nguyen bat ki (x, n): ");
    scanf("%d %d", &x, &n);
    
    // Tính S(n) từ i = 0 đến n
    for (int i = 0; i < n; i++) {
        double luyThua = pow(x, 2*i + 1);  // Tính x^(2*i + 1)
        int mau = giaiThua(2*i + 1); // Tính (2*i + 1)!
        ketQua += luyThua / mau; // Cộng thêm x^(2*i + 1) / (2*i + 1)! vào ketQua
        printf("Tong sau lan lap thu %d la: %6f\n", i + 1, ketQua); // In ra tổng hiện tại
    }
    
    printf("Tong ket qua la: %6f\n", ketQua); // In ra tổng kết quả
    return 0;
}
