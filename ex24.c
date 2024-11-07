#include <stdio.h>

int main() {
    int n;
    printf("Hãy nhập số nguyên dương n: ");
    scanf("%d", &n);

    printf("Các ước số lẻ của %d là: ", n);
    for (int i = 1; i <= n; i++) {
        // Kiểm tra nếu i là ước của n và i là số lẻ
        if (n % i == 0 && i % 2 == 1) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
