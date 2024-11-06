#include <stdio.h>

int main() {
    int x, n, ketQua = 0;
    printf("Hay nhap 2 so bat ki (x va n): ");
    scanf("%d %d", &x, &n);
    
    int luyThua = 1;  // Bắt đầu với x^0 = 1
    for (int i = 1; i <= n; i++) {
        luyThua *= x;  // Tính x^i bằng cách nhân thêm x vào lũy thừa hiện tại
        ketQua += luyThua;  // Cộng lũy thừa vào tổng
        printf("Ket qua i = %d la %d\n", i, ketQua);
    }
    
    printf("Tong ket qua la: %d\n", ketQua);
    return 0;
}
