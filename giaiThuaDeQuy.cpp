// Viết hàm đệ quy để tính n! (giai thừa của n)

#include <stdio.h>

int giaiThua(int n) {
    if (n < 0) return -1;  // Trả về -1 nếu n âm (không có giai thừa)
    if (n == 0 || n == 1) return 1;
    return n * giaiThua(n - 1);
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
