// Bài 355: Liệt kê các dòng toàn âm trong ma trận các số thực
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

void kiemTraDongAm(float *arr, int n, int m) {
    int coDongAm = 0;  // Biến kiểm tra có dòng toàn âm hay không

    for (int i = 0; i < n; i++) {
        int flag = 1;  // Đặt lại cờ cho từng dòng

        for (int j = 0; j < m; j++) {
            if (arr[i * m + j] >= 0) { // Nếu có số >= 0, không phải dòng toàn âm
                flag = 0;
                break;
            }
        }

        if (flag) {
            printf("%d ", i);
            coDongAm = 1;
        }
    }

    if (!coDongAm) {
        printf("Không có dòng nào toàn âm.");
    }
}

int main() {
    int n, m;
    printf("\nNhập hàng và cột: ");
    scanf("%d%d", &n, &m);

    float *arr = (float *)malloc(n * m * sizeof(float));
    if (arr == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    printf("\nCác dòng toàn âm trong ma trận là: ");
    kiemTraDongAm(arr, n, m);

    free(arr);
    return 0;
}
