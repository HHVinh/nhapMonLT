#include <stdio.h>

#define SCREEN_WIDTH 80 // Giả định độ rộng màn hình là 80 ký tự

void inTamGiac(int h) {
    int base_width = 2 * h - 1; // Độ rộng của tam giác ở dòng cuối
    int left_padding = (SCREEN_WIDTH - base_width) / 2; // Khoảng trắng để căn giữa

    for (int i = 1; i <= h; i++) {
        // In khoảng trắng để căn giữa
        for (int j = 1; j <= left_padding + (h - i); j++) {
            printf(" ");
        }
        // In dấu sao '*'
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        // Xuống dòng sau mỗi hàng
        printf("\n");
    }
}

int main() {
    int h;
    printf("Hãy nhập chiều cao tam giác: ");
    scanf("%d", &h);
    inTamGiac(h);
    return 0;
}
