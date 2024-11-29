#include <stdio.h>

// Nhập mảng 2 chiều
void Nhap(int m, int n, float a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhập giá trị của hàng %d - cột %d: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
}

// Xuất mảng 2 chiều
void Xuat(int m, int n, float a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

// Sắp xếp mảng 2 chiều
void SapXep(int m, int n, float a[100][100]) {
    float b[10000];  // Mảng 1 chiều để sắp xếp
    int Dem = 0;

    // Chuyển dữ liệu từ mảng 2 chiều sang mảng 1 chiều
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            b[Dem++] = a[i][j];
        }
    }

    // Sắp xếp mảng 1 chiều tăng dần (Bubble Sort)
    for (int i = 0; i < Dem - 1; i++) {
        for (int j = i + 1; j < Dem; j++) {
            if (b[i] > b[j]) {
                float temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }

    // Chuyển dữ liệu từ mảng 1 chiều đã sắp xếp trở lại mảng 2 chiều
    Dem = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = b[Dem++];
        }
    }
}

int main() {
    int m, n;
    float a[100][100];

    printf("Nhập số hàng và cột của mảng hai chiều MxN: ");
    scanf("%d %d", &m, &n);

    Nhap(m, n, a);
    printf("Mảng vừa nhập là:\n");
    Xuat(m, n, a);

    printf("\nSắp xếp mảng theo thứ tự tăng dần:\n");
    SapXep(m, n, a);
    Xuat(m, n, a);

    return 0;
}
