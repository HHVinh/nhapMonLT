// Bài 323: Tính tích các giá trị dương trên 1 cột trong ma trận các số thực
#include <stdio.h>
#include <stdlib.h>

void nhap(float *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%f", &arr[i]);
    }
}

void xuat(float *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%8.2f", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

float tichGiaTriDuong1Cot(float *arr, int n, int m, int k) {
    float tich = 1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        float value = arr[i * m + k]; // Truy cập phần tử tại cột k của dòng i
        if (value > 0) {
            tich *= value;
            count++;
        }
    }

    return (count > 0) ? tich : 1; // Nếu không có số dương, trả về 1
}

int main() {
    int n, m;
    printf("\nNhập số hàng và số cột: ");
    if (scanf("%d%d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("\nLỗi: Số hàng và số cột phải là số nguyên dương!\n");
        return 1;
    }

    float *arr = (float *)malloc(n * m * sizeof(float));
    if (arr == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        return 1;
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    int k;
    do {
        printf("\nNhập cột muốn tính tích (từ 0 đến %d): ", m - 1);
        scanf("%d", &k);
        if (k < 0 || k >= m) {
            printf("\nLỗi: Cột phải nằm trong khoảng từ 0 đến %d. Vui lòng nhập lại!\n", m - 1);
        }
    } while (k < 0 || k >= m);

    float ketQua = tichGiaTriDuong1Cot(arr, n, m, k);
    if (ketQua == 1) {
        printf("\nKhông có số dương trong cột %d.", k);
    } else {
        printf("\nTích các số dương của cột %d là: %8.2f", k, ketQua);
    }

    free(arr);
    return 0;
}
