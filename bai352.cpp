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

// Hàm kiểm tra hàng thứ k có tăng dần hay không (dùng cờ hiệu)
void kiemTraHangTang(int *arr, int m, int k) {
    int flag = 1;  // Cờ hiệu: giả sử ban đầu hàng k tăng dần

    for (int i = k * m; i < k * m + m - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            flag = 0;  // Phát hiện không tăng dần
            break;     // Thoát khỏi vòng lặp ngay khi tìm thấy phần tử không hợp lệ
        }
    }

    // Kiểm tra giá trị của flag sau vòng lặp
    if (flag) {
        printf("\nHàng %d của ma trận tăng dần.", k);
    } else {
        printf("\nHàng %d của ma trận không tăng dần.", k);
    }
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

    // Nhập dòng cần kiểm tra
    int k;
    do {
        printf("\nNhập dòng cần kiểm tra (từ 0 đến %d): ", n - 1);
        scanf("%d", &k);
        if (k >= n || k < 0) {
            printf("\nNhập lại dòng cần kiểm tra.");
        }
    } while (k >= n || k < 0);

    // Kiểm tra hàng k có tăng dần không
    kiemTraHangTang(arr, m, k);

    // Giải phóng bộ nhớ
    free(arr);
    return 0;
}
