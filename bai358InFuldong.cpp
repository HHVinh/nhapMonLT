// Bài 358: Liệt kê các dòng có chứa giá trị chẵn trong ma trận các số nguyên
#include <stdio.h>
#include <stdlib.h>

// Hàm nhập ma trận
void nhap(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

// Hàm xuất ma trận
void xuat(int *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) {
            printf("\n");
        }
    }
}

// Hàm liệt kê các dòng có chứa ít nhất một số chẵn và in cả dòng đó ra
void lietKeDongCoSoChan(int *arr, int n, int m) {
    int coDong = 0;

    printf("\nCác dòng chứa ít nhất một số chẵn là:\n");

    for (int i = 0; i < n; i++) {
        int coSoChan = 0;

        for (int j = 0; j < m; j++) {
            if (arr[i * m + j] % 2 == 0) {
                coSoChan = 1;
                break;
            }
        }

        if (coSoChan) {
            printf("Dòng %d:", i);
            for (int j = 0; j < m; j++) {
                printf("%5d", arr[i * m + j]);
            }
            printf("\n");
            coDong = 1;
        }
    }

    if (!coDong) {
        printf("Không có dòng nào chứa số chẵn.\n");
    }
}

int main() {
    int n, m;
    printf("Nhập số hàng và số cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int *)malloc(n * m * sizeof(int));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        return 1;
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    lietKeDongCoSoChan(arr, n, m);

    free(arr);
    return 0;
}
