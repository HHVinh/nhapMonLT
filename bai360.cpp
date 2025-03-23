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

int soChinhPhuong(int a){
    if(a < 0) return 0;
    int num = sqrt(a);
    return (num * num == a) ? 1 : 0;
}


void kiemTraCotCoSoChinhPhuong(int *arr, int n, int m) {
    int coCot = 0;  // Biến kiểm tra có cột thỏa điều kiện không?
    int giaTriDau = 1; // Đánh dấu lần đầu in

    for (int i = 0; i < m; i++) {
        int flag = 0;  // Đặt lại cờ cho cột

        for (int j = 0; j < n; j++) {
            if (soChinhPhuong(arr[j * m + i])) { // Nếu có số chính phương
                flag = 1;
                break;
            }
        }

        if (flag) {
            if(!giaTriDau){
                printf(", "); // Chỉ in dấu phẩy khi không phải số đầu
            }
            printf("%d", i);
            coCot = 1;
            giaTriDau = 0;
        }
    }

    if (!coCot) {
        printf("Không có cột nào chứa số chính phương.");
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
    xuat(arr, n, m);

    printf("\nCác cột có số chính phương trong ma trận là: ");
    kiemTraCotCoSoChinhPhuong(arr, n, m);

    free(arr);
    return 0;
}
