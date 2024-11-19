#include <stdio.h>

void inTamGiacVuongCanRong(int h) {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1 || i == h || i == j) {
                printf("*"); // In dấu sao ở cạnh dọc, đường chéo hoặc cạnh đáy
            } else {
                printf(" "); // In khoảng trắng bên trong
            }
        }
        printf("\n"); // Xuống dòng sau mỗi hàng
    }
}

int main() {
    int h;
    printf("Nhập chiều cao tam giác vuông cân rỗng: ");
    scanf("%d", &h);
    inTamGiacVuongCanRong(h);
    return 0;
}
