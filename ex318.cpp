#include <stdio.h>

// Hàm nhập ma trận
void Nhap(int m, int n, float a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhập giá trị cho hàng %d và cột %d: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
}

// Hàm xuất ma trận
void Xuat(int m, int n, float a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

// Hàm tính tổng các số âm
float TongSoAm(int m, int n, float a[100][100]) {
    float Tong = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] < 0) {
                Tong += a[i][j];
            }
        }
    }
    return Tong;
}

// Hàm chính
int main() {
    int m, n;
    float a[100][100];

    // Nhập kích thước ma trận
    printf("Hãy nhập số hàng và số cột cho ma trận MxN: ");
    scanf("%d %d", &m, &n);

    // Nhập ma trận
    Nhap(m, n, a);
    
    // Xuất ma trận
    printf("Mảng vừa nhập là:\n");
    Xuat(m, n, a);

    // Tính và in kết quả tổng các số âm
    float KetQua = TongSoAm(m, n, a);
    printf("Tổng các số âm trong ma trận là: %.2f\n", KetQua);

    return 0;
}
