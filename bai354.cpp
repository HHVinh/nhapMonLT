// Bài 354: Kiểm tra các giá trị trong ma trận có giảm dần theo dòng và cột hay không
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
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) {
            printf("\n");
        }
    }
}

// Hàm kiểm tra dòng có giảm dần hay không
int kiemTraDongGiam(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {  // Duyệt từng dòng
        for (int j = 0; j < m - 1; j++) {  // So sánh từng cặp phần tử trong dòng
            if (arr[i * m + j] < arr[i * m + j + 1]) {
                return 0;  // Nếu có một cặp sai, trả về false (0)
            }
        }
    }
    return 1;  // Nếu không có cặp nào sai, trả về true (1)
}

// Hàm kiểm tra cột có giảm dần hay không
int kiemTraCotGiam(int *arr, int n, int m) {
    for (int j = 0; j < m; j++) {  // Duyệt từng cột
        for (int i = 0; i < n - 1; i++) {  // So sánh từng cặp phần tử trong cột
            if (arr[i * m + j] < arr[(i + 1) * m + j]) {
                return 0;  // Nếu có một cặp sai, trả về false (0)
            }
        }
    }
    return 1;  // Nếu không có cặp nào sai, trả về true (1)
}

int main() {
    int n, m;
    printf("\nNhập số lượng dòng và cột: ");
    scanf("%d %d", &n, &m);

    // Cấp phát bộ nhớ động cho ma trận
    int *arr = (int *)malloc(n * m * sizeof(int));
    if (arr == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    // Nhập ma trận và hiển thị
    nhap(arr, n, m);
    printf("\nMa trận là: \n");
    xuat(arr, n, m);

    // Kiểm tra dòng và cột
    int dongGiam = kiemTraDongGiam(arr, n, m);
    int cotGiam = kiemTraCotGiam(arr, n, m);

    // Xuất kết quả
    if (dongGiam && cotGiam) {
        printf("\nMa trận giảm dần theo cả dòng và cột.\n");
    } else {
        printf("\nMa trận không giảm dần theo cả dòng và cột.\n");
    }

    // Giải phóng bộ nhớ
    free(arr);
    return 0;
}
