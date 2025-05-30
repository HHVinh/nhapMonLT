// Viết hàm đệ quy để kiểm tra một số nguyên n có phải là số nguyên tố hay không
#include <stdio.h>

int laSoNguyenTo(int n, int i) {
    if (n < 2) return 0;        // Số nhỏ hơn 2 không phải nguyên tố
    if (i == 1) return 1;      // Kiểm tra đến 1 thì là số nguyên tố
    if (n % i == 0) return 0;  // Chia hết => không phải số nguyên tố
    return laSoNguyenTo(n, i - 1);
}

int main() {
    int n;
    printf("Nhập số nguyên: ");
    scanf("%d", &n);

    if (laSoNguyenTo(n, n / 2))
        printf("%d là số nguyên tố\n", n);
    else
        printf("%d không phải số nguyên tố\n", n);

    return 0;
}
