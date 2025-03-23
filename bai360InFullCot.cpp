// Bài 360: Liệt kê các cột trong ma trận các số nguyên có chứa số chính phương
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

// Kiểm tra số chính phương
int soChinhPhuong(int a){
    if(a < 0) return 0;
    int num = sqrt(a);
    return (num * num == a) ? 1 : 0;
}

// Hàm liệt kê các cột có chứa số chính phương
void kiemTraCotCoSoChinhPhuong(int *arr, int n, int m) {
    int coCot = 0;
    int *chiSoCot = (int*) calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (soChinhPhuong(arr[j * m + i])) {
                coCot = 1;
                chiSoCot[i] = 1;
                break;
            }
        }
    }

    if(coCot){
        printf("\nCác cột chứa số chính phương là: \n");
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(chiSoCot[j]){
                    printf("%5d", arr[i * m + j]);
                }
            }
            printf("\n");
        }
    } else {
        printf("Không có cột nào chứa số chính phương.");
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

    kiemTraCotCoSoChinhPhuong(arr, n, m);

    free(arr);
    return 0;
}
