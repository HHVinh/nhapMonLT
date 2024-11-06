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
    printf("Hay nhap 2 so nguyen bat ki: ");
    scanf("%d %d", &x, &n);
    
    double luyThua = 1.0; // luyThua cho x^(2*i)
    for (int i = 1; i <= n; i++) {
        luyThua = pow(x, 2*i);  // Tính x^(2*i)
        int mau = giaiThua(2*i); // Tính (2*i)!
        ketQua += luyThua / mau; // Cộng thêm x^(2*i) / (2*i)! vào ketQua
        printf("Tong sau lan lap thu %d la: %6f\n", i, ketQua); // In ra tổng hiện tại
    }
    
    printf("Tong ket qua la: %6f\n", ketQua); // In ra tổng kết quả
    return 0;
}
