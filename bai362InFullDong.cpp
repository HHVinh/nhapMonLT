// Bài 362: Liệt kê các dòng giảm dần trong ma trận
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

// Hàm liệt kê các dòng giảm dần
void kiemTraDongGiamDan(int *arr, int n, int m) {
    int thoaDieuKien = 0;

    for (int i = 0; i < n; i++) {
        int flag = 1;
        for (int j = 0; j < m-1; j++) {
            if(arr[i * m + j] < arr[i * m + j + 1]) {
                flag = 0;
                break;
            }
        }
        if(flag){
            thoaDieuKien = 1;
            printf("\nDong %d:", i);
            for(int j = 0; j < m; j++){
                printf("%5d", arr[i * m + j]);
            }
            printf("\n");
        }
    }

    if(!thoaDieuKien){
        printf("\nKhông tồn tại dòng giảm dần: \n");
    }
}

int main() {
    int n, m;
    printf("\nNhập hàng và cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int *)malloc(n * m * sizeof(int));
    if (arr == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\nMa trận vừa nhập là:\n");
    xuat(arr, n, m);

    kiemTraDongGiamDan(arr, n, m);

    free(arr);
    return 0;
}
