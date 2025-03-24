// Bài 363: Liệt kê các cột tăng dần trong ma trận
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

// Hàm kiểm tra cột tăng dần
void kiemTraCotTangDan(int *arr, int n, int m) {
    int thoaDieuKien = 0;
    int *chiSoCot = (int*) calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j * m + i] > arr[(j + 1) * m + i] ) {
                chiSoCot[i] = 1;
                break;
            }
        }
    }

    for(int i = 0; i < m; i++){
        if(chiSoCot[i] == 0){
            thoaDieuKien = 1;
            break;
        }
    }

    if(thoaDieuKien){
        printf("\nCác cột tăng dần là: \n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(chiSoCot[j] == 0){
                    printf("%5d", arr[i * m + j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("Không có cột nào tăng dần.");
    }
    free(chiSoCot);
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

    kiemTraCotTangDan(arr, n, m);

    free(arr);
    return 0;
}
