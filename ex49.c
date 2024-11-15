#include <stdio.h>

int main() {
    int n;
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Liên tục chia n cho 10 cho đến khi chỉ còn lại một chữ số
    while (n >= 10) {
        n /= 10;
    }

    // In ra chữ số đầu tiên
    printf("Chữ số đầu tiên của n là: %d\n", n);
    return 0;
}
