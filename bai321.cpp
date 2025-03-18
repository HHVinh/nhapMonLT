// Bài 321: Tính tích các giá trị lẻ trong ma trận các số nguyên
#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

int tichSoLe(int *arr, int n, int m) {
    int tich = 1;
    int count = 0;
    for (int i = 0; i < n * m; i++) {
        if (arr[i] % 2 != 0) {
            tich *= arr[i];
            count++;
        }
    }
    if (count > 0) {
        return tich;  // Trả về tích số lẻ
    } else {
        return 1;  // Nếu không có số lẻ, trả về 1 để tránh sai sót
    }
}

int main() {
    int n, m;
    printf("\nNhập hàng và cột: ");
    if (scanf("%d%d", &n, &m) != 2 || n <= 0 || m <= 0) {
        printf("\nLỗi: Số hàng và số cột phải là số nguyên dương!\n");
        return 1;
    }

    int *arr = (int *)malloc(n * m * sizeof(int));
    if (arr == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        return 1;
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    int ketQua = tichSoLe(arr, n, m);
    if (ketQua == 1) {
        printf("\nKhông có số lẻ trong ma trận vừa nhập.\n");
    } else {
        printf("\nTích các số lẻ là: %d\n", ketQua);
    }

    free(arr);
    return 0;
}
