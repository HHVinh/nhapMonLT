#include <stdio.h>

void inTamGiacVuongCan(int h) {
    for (int i = 1; i <= h; i++) {
        // In dấu sao '*' mỗi dòng
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n"); // Xuống dòng sau mỗi hàng
    }
}

int main() {
    int h;
    printf("Nhập chiều cao tam giác vuông cân đặc: ");
    scanf("%d", &h);
    inTamGiacVuongCan(h);
    return 0;
}
