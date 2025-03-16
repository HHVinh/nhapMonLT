#include <stdio.h>
#include <stdlib.h>

// Hàm nhập ma trận số thực
void nhap(float *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập A[%d][%d]: ", i / m, i % m);
        scanf("%f", &arr[i]);
    }
}

// Hàm xuất ma trận
void xuat(float *arr, int n, int m) {
    printf("\nMa trận là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%8.3f", arr[i]);
        if ((i + 1) % m == 0) {
            printf("\n");
        }
    }
}

// Hàm sắp xếp ma trận theo thứ tự tăng dần từ trên xuống dưới, từ trái sang phải
void sapXepTangDan(float *arr, int n, int m) {
    int size = n * m;
    
    // Sắp xếp toàn bộ phần tử trong mảng 1 chiều
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    // Tạo một mảng tạm để lưu giá trị đã sắp xếp theo yêu cầu
    float *sortedArr = (float *)malloc(size * sizeof(float));
    if (sortedArr == NULL) {
        printf("Lỗi cấp phát bộ nhớ!");
        return;
    }

    // Đưa các phần tử vào ma trận theo thứ tự cột trước, hàng sau
    int index = 0;
    for (int j = 0; j < m; j++) {   // Duyệt từng cột trước
        for (int i = 0; i < n; i++) {  // Sau đó duyệt từng hàng
            sortedArr[i * m + j] = arr[index++];
        }
    }

    // Sao chép kết quả đã sắp xếp trở lại mảng chính
    for (int i = 0; i < size; i++) {
        arr[i] = sortedArr[i];
    }

    // Giải phóng bộ nhớ tạm
    free(sortedArr);
}

int main() {
    int n, m;
    
    // Nhập số dòng và số cột của ma trận
    printf("Nhập số dòng và số cột: ");
    scanf("%d %d", &n, &m);
    
    // Cấp phát bộ nhớ động cho ma trận
    float *arr = (float*) malloc(n * m * sizeof(float));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ!");
        return 1;
    }
    
    // Nhập, xuất ma trận trước khi sắp xếp
    nhap(arr, n, m);
    xuat(arr, n, m);
    
    // Sắp xếp và xuất lại ma trận đã sắp xếp
    sapXepTangDan(arr, n, m);
    printf("\nMa trận sau khi sắp xếp tăng dần từ trên xuống dưới, từ trái sang phải:\n");
    xuat(arr, n, m);
    
    // Giải phóng bộ nhớ
    free(arr);
    
    return 0;
}
