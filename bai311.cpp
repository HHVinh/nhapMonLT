// Bài 311 + 313: Viết hàm nhập xuất ma trận số nguyên
#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m) {
    printf("\nMa trận là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) {
            printf("\n");
        }
    }
}

int main() {
    int n, m;
    printf("Nhập số lượng n (dòng) và m (cột): ");
    scanf("%d%d", &n, &m);

    int *arr = (int *)malloc(n * m * sizeof(int));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        return 1;
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    free(arr);
    return 0;
}
