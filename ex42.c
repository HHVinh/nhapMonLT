#include <stdio.h>

int main() {
    int n, k = 0, tong = 0;
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Lặp để tìm giá trị k
    while (tong + (k + 1) < n) {
        k++;
        tong += k;
    }

    printf("Giá trị k lớn nhất thỏa mãn S(k) < n là: %d\n", k);
    return 0;
}
