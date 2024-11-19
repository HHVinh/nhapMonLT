#include <stdio.h>

void inTamGiac(int h){
    for (int i = 1; i <= h; i++)
    {
        // In khoảng trắng
        for (int j = 1; j <= h - i; j++) {
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
