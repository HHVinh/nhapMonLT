#include <stdio.h>

// Hàm kiểm tra bit thứ k của số n có bật (là 1) hay không
void kiemTraBitAND(int n, int k) {
    if (n & (1 << k)) {
        printf("Bit thu %d cua %d la 1\n", k, n);
    } else {
        printf("Bit thu %d cua %d la 0\n", k, n);
    }
}

int main() {
    int n = 10; // 1010
    int k = 1;
    kiemTraBitAND(n, k);  // Kết quả: bit thứ 1 là 1
    return 0;
}
