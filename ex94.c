#include <stdio.h>

// Hàm in các số lẻ dưới 100
void inSoLe() {
    for (int i = 1; i < 100; i += 2) {  // Bắt đầu từ 1 và tăng dần 2 để có các số lẻ
        if (i == 5 || i == 7 || i == 93) {
            continue;  // Bỏ qua các số 5, 7 và 93
        }
        printf("%d ", i);  // In số lẻ
    }
}

int main() {
    printf("Các số lẻ dưới 100 là: ");
    inSoLe();  // Gọi hàm in các số lẻ
    return 0;
}
