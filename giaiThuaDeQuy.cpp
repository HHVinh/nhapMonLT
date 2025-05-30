// Viết hàm đệ quy để tính n! (giai thừa của n)

#include <stdio.h>

int giaiThua(int n) {
    if (n < 0) return -1;  // Trả về -1 nếu n âm (không có giai thừa)
    if (n == 0 || n == 1) return 1;
    return n * giaiThua(n - 1);
}

// Hàm đệ quy tính giai thừa chẵn GTC(n)
int giaiThuaChan(int n) {
    if (n < 0) return -1;  // Trả về -1 nếu n âm (không có giai thừa)
    if (n == 0)   // GTC(0) = 1, cũng áp dụng với n < 0 để tránh lỗi
        return 1;

    if (n % 2 == 0)  // n chẵn
        return n * giaiThuaChan(n - 2);
    else             // n lẻ
        return (n - 1) * giaiThuaChan(n - 3);
}

// Hàm đệ quy tính giai thừa lẻ GTL(n)
int giaiThuaLe(int n) {
    if (n <= 0) return -1;  // Trả về -1 nếu n âm (không có giai thừa)
    if (n == 1)
        return 1;

    if (n % 2 == 1)
        return n * giaiThuaLe(n - 2);
    else
        return (n - 1) * giaiThuaLe(n - 3);
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int kq = giaiThua(n);
    if (kq == -1)
        printf("Khong tinh duoc giai thua cua so am.\n");
    else
        printf("%d! = %d\n", n, kq);

    return 0;
}
