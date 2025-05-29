#include <stdio.h>

// Hàm bật bit thứ k của số n
int batBitOR(int n, int k) {
    return n | (1 << k);
}

int main() {
    int n = 10; // 1010
    int k = 0;
    int ketQua = batBitOR(n, k); // Kết quả: 1011 = 11
    printf("Sau khi bat bit thu %d: %d\n", k, ketQua);
    return 0;
}
