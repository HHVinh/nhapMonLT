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

// Hàm kiểm tra cột thứ k có giảm dần hay không
void kiemTraCotGiam(int *arr, int n, int m, int k) {
    int flag = 1;  // Cờ hiệu: giả sử ban đầu cột k giảm dần

    if (n == 1) {
        printf("\nCột %d của ma trận được coi là giảm dần vì chỉ có 1 phần tử.", k);
        return;
    }

    for (int i = k; i + m < n * m; i += m) {  // Sửa điều kiện kiểm tra
        if (arr[i] < arr[i + m]) {
            flag = 0;  // Phát hiện không giảm dần
            break;     // Thoát khỏi vòng lặp ngay khi tìm thấy phần tử không hợp lệ
        }
    }

    // Kiểm tra giá trị của flag sau vòng lặp
    if (flag) {
        printf("\nCột %d của ma trận giảm dần.", k);
    } else {
        printf("\nCột %d của ma trận không giảm dần.", k);
    }
}

int main() {
    int n, m;
    printf("\nNhập số lượng dòng và cột: ");  // Sửa lỗi chính tả
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

    // Nhập cột cần kiểm tra
    int k;
    do {
        printf("\nNhập cột cần kiểm tra (từ 0 đến %d): ", m - 1);
        scanf("%d", &k);
        if (k >= m || k < 0) {  // Sửa lỗi kiểm tra điều kiện
            printf("\nNhập lại cột cần kiểm tra.");
        }
    } while (k >= m || k < 0);

    // Kiểm tra cột k có giảm dần không
    kiemTraCotGiam(arr, n, m, k);

    // Giải phóng bộ nhớ
    free(arr);
    return 0;
}
