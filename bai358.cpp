// Bài 358: Liệt kê các dòng có chứa giá trị chẵn trong ma trận các số nguyên
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


void kiemTraDongToanSoChan(int *arr, int n, int m) {
    int coDongChan = 0;  // Biến kiểm tra có dòng toàn số chẵn hay không?
    int giaTriDau = 1; // Đánh dấu lần đầu in

    for (int i = 0; i < n; i++) {
        int flag = 1;  // Đặt lại cờ cho từng dòng

        for (int j = 0; j < m; j++) {
            if ((arr[i * m + j] % 2 != 0)) { // Nếu có số không phải số chẵn
                flag = 0;
                break;
            }
        }

        if (flag) {
            if(!giaTriDau){
                printf(", "); // Chỉ in dấu phẩy khi không phải số đầu
            }
            printf("%d", i);
            coDongChan = 1;
            giaTriDau = 0;
        }
    }

    if (!coDongChan) {
        printf("Không có dòng nào toàn số chẵn.");
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

    printf("\nCác dòng toàn số chẵn trong ma trận là: ");
    kiemTraDongToanSoChan(arr, n, m);

    free(arr);
    return 0;
}
