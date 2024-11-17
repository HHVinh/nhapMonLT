#include <stdio.h>

void inSoLe() {
    // Duyệt qua các số lẻ từ 1 đến 99
    for (int i = 1; i < 100; i += 2) {
        // In các số lẻ trừ 5, 7 và 93
        if (i != 5 && i != 7 && i != 93) {
            printf("%d ", i);  // In số lẻ
        }
    }
}

int main() {
    printf("Các số lẻ dưới 100 là: ");
    inSoLe();  // Gọi hàm in các số lẻ
    return 0;
}
