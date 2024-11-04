#include <stdio.h>

int main() {
    int x, n;
    int ketQua = 1;  // Khởi tạo ketQua = 1, vì tích ban đầu là 1

    // Nhập giá trị x và n từ người dùng
    printf("Hay nhap x va n: ");
    scanf("%d %d", &x, &n);
    
    // Tính x^n bằng cách nhân x với chính nó n lần
    for(int i = 1; i <= n; i++) {
        ketQua *= x;  // Nhân ketQua với x trong mỗi vòng lặp
        printf("Gia tri cua x^%d la: %d\n", i, ketQua);  // In ket qua o tung buoc
    }

    // In kết quả cuối cùng
    printf("Ket qua x^%d la: %d\n", n, ketQua);
    return 0;
}
