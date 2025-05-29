// Viết hàm đệ quy tính tổng các chữ số của một số nguyên n
#include <stdio.h>
#include <stdlib.h>

// Hàm đệ quy tính tổng chữ số
int tinhTongChuSo(int n) {
    if (n < 0) n = -n;  // Bổ sung: nếu n là số âm, chuyển thành dương

    if (n < 10) {
        return n;
    }

    return n % 10 + tinhTongChuSo(n / 10);
}

int main() {
    int n;
    printf("Nhap so nguyen n: ");
    scanf("%d", &n);

    int tong = tinhTongChuSo(n);
    printf("Tong cac chu so cua %d la: %d\n", n, tong);
    return 0;
}
