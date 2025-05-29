// Viết hàm hoán đổi giá trị của hai con trỏ int* a và int* b mà không sử dụng biến tạm thời (gợi ý: dùng phép XOR)
#include <stdio.h>

void hoanDoi(int* a, int* b) {
    if (a == b) return;

    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

int main() {
    int x = 5, y = 10;
    printf("Trước khi hoán đổi: x = %d, y = %d\n", x, y);

    hoanDoi(&x, &y);

    printf("Sau khi hoán đổi: x = %d, y = %d\n", x, y);
    return 0;
}
