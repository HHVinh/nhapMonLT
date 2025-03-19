// Bài 342(*): Đếm số lượng phần tử cực đại trong ma trận các số thực.
// Một phần tử được gọi là cực đại khi nó lớn hơn các phần tử xung quanh

#include <stdio.h>
#include <stdlib.h>

// Hàm nhập ma trận
void nhap(float *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhập phần tử A[%d][%d]: ", i, j);
            scanf("%f", &arr[i * m + j]);
        }
    }
}

// Hàm xuất ma trận
void xuat(float *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%8.2f", arr[i * m + j]);
        }
        printf("\n");
    }
}

// Hàm kiểm tra phần tử (i, j) có phải cực đại hay không
int laCucDai(float *arr, int n, int m, int i, int j) {
    float current = arr[i * m + j];

    // Kiểm tra 8 hướng nếu không vượt biên
    if (i > 0 && arr[(i - 1) * m + j] >= current) return 0; // Trên
    if (i < n - 1 && arr[(i + 1) * m + j] >= current) return 0; // Dưới
    if (j > 0 && arr[i * m + (j - 1)] >= current) return 0; // Trái
    if (j < m - 1 && arr[i * m + (j + 1)] >= current) return 0; // Phải
    if (i > 0 && j > 0 && arr[(i - 1) * m + (j - 1)] >= current) return 0; // Trên trái
    if (i > 0 && j < m - 1 && arr[(i - 1) * m + (j + 1)] >= current) return 0; // Trên phải
    if (i < n - 1 && j > 0 && arr[(i + 1) * m + (j - 1)] >= current) return 0; // Dưới trái
    if (i < n - 1 && j < m - 1 && arr[(i + 1) * m + (j + 1)] >= current) return 0; // Dưới phải

    return 1; // Nếu không có phần tử nào lớn hơn, đây là phần tử cực đại
}

// Hàm đếm số phần tử cực đại
int demPhanTuCucDai(float *arr, int n, int m) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laCucDai(arr, n, m, i, j)) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n, m;
    printf("Nhập số dòng và số cột: ");
    scanf("%d %d", &n, &m);

    float *arr = (float *)malloc(n * m * sizeof(float));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    int ketQua = demPhanTuCucDai(arr, n, m);
    printf("\nSố phần tử cực đại trong ma trận là: %d\n", ketQua);

    free(arr);
    return 0;
}
