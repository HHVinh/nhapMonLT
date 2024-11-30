#include <stdio.h>

void Nhap(int m, int n, int a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhập giá trị của hàng %d - cột %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void Xuat(int m, int n, int a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int TinhTichSoLe(int m, int n, int a[100][100]) {
    int Tich = 1;
    int CoSoLe = 0; // Cờ kiểm tra có số lẻ hay không
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                Tich *= a[i][j];
                CoSoLe = 1; // Đánh dấu tìm thấy số lẻ
            }
        }
    }
    return CoSoLe ? Tich : 0; // Nếu không có số lẻ, trả về 0
}

int main() {
    int m, n;
    int a[100][100];

    printf("Nhập số hàng và cột của mảng hai chiều MxN: ");
    scanf("%d %d", &m, &n);

    Nhap(m, n, a);
    printf("Mảng vừa nhập là:\n");
    Xuat(m, n, a);

    int Tich = TinhTichSoLe(m, n, a);
    if (Tich == 0) {
        printf("Không có số lẻ trong mảng.\n");
    } else {
        printf("Tích các số lẻ trong mảng là: %d\n", Tich);
    }

    return 0;
}
