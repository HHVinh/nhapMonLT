// Bài 318: Viết hàm tính tổng các giá trị âm trong ma trận số thực
#include <stdio.h>
#include <stdlib.h>

// Hàm nhập ma trận số thực từ bàn phím
void nhap(float *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%f", &arr[i]);
    }
}

// Hàm xuất ma trận ra màn hình
void xuat(float *arr, int n, int m) {
    printf("\nMa trận vừa nhập:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%8.3f", arr[i]);  // Hiển thị số với 3 chữ số thập phân
        if ((i + 1) % m == 0) {
            printf("\n");
        }
    }
}

// Hàm tính tổng các giá trị âm trong ma trận
float tongGiaTriAm(float *arr, int n, int m) {
    float sum = 0;  // Biến lưu tổng các số âm
    
    for (int i = 0; i < n * m; i++) {
        if (arr[i] < 0) {
            sum += arr[i];  // Cộng dồn các số âm
        }
    }

    if (sum == 0) {
        printf("\nKhông có giá trị âm trong ma trận.");
    } else {
        printf("\nTổng các giá trị âm trong ma trận là: %8.3f", sum);
    }
    
    return sum;  // Trả về tổng các số âm
}

int main() {
    int n, m;

    // Nhập số dòng và số cột của ma trận
    printf("Nhập số dòng và số cột của ma trận: ");
    scanf("%d %d", &n, &m);

    // Cấp phát động cho mảng 1 chiều để lưu ma trận
    float *arr = (float*) malloc(n * m * sizeof(float));
    if (arr == NULL) {  // Kiểm tra cấp phát bộ nhớ
        printf("Lỗi cấp phát bộ nhớ.");
        return 1;
    }

    // Nhập và xuất ma trận
    nhap(arr, n, m);
    xuat(arr, n, m);

    // Tính tổng các giá trị âm
    tongGiaTriAm(arr, n, m);

    // Giải phóng bộ nhớ đã cấp phát
    free(arr);

    return 0;
}
