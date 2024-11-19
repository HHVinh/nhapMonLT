#include <stdio.h>

void inHinhChuNhatDac(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            printf("*"); // In dấu '*'
        }
        printf("\n"); // Xuống dòng sau mỗi hàng
    }
}

void inHinhChuNhatRong(int m, int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            // In dấu '*' ở cạnh trên, cạnh dưới, hoặc cột đầu và cuối
            if (i == 1 || i == m || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" "); // In khoảng trắng bên trong
            }
        }
        printf("\n"); // Xuống dòng sau mỗi hàng
    }
}

int main() {
    int m, n;
    printf("Nhập chiều cao (m) và chiều rộng (n) của hình chữ nhật: ");
    scanf("%d %d", &m, &n);
    printf("Hình chữ nhật đặc:\n");
    inHinhChuNhatDac(m, n);
    printf("\nHình chữ nhật rỗng:\n");
    inHinhChuNhatRong(m, n);
    return 0;
}
