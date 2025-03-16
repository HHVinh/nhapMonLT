// Bài 317: Viết hàm tính trung bình cộng các số nguyên tố trong ma trận số nguyên
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
    printf("\nMa trận là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);  // In khoảng cách giữa các số để dễ đọc
        if ((i + 1) % m == 0) {
            printf("\n"); // Xuống dòng sau mỗi hàng
        }
    }
}

// Hàm kiểm tra một số có phải số nguyên tố hay không
int kiemTraSoNguyenTo(int a) {
    if (a < 2) return 0; // Số nhỏ hơn 2 không phải số nguyên tố
    for (int i = 2; i <= sqrt(a); i++) { // Kiểm tra từ 2 đến sqrt(a)
        if (a % i == 0) return 0; // Nếu chia hết thì không phải số nguyên tố
    }
    return 1; // Nếu không chia hết cho số nào, là số nguyên tố
}

// Hàm tính trung bình cộng các số nguyên tố trong ma trận
float trungBinhSoNguyenTo(int *arr, int n, int m) {
    int sum = 0, count = 0; // Biến sum để tính tổng, count để đếm số nguyên tố

    for (int i = 0; i < n * m; i++) {
        if (kiemTraSoNguyenTo(arr[i])) { // Nếu phần tử là số nguyên tố
            sum += arr[i]; // Cộng vào tổng
            count++; // Tăng biến đếm số lượng số nguyên tố
        }
    }

    if (count == 0) { // Nếu không có số nguyên tố nào
        printf("\nKhông có số nguyên tố trong ma trận.");
        return -1; // Trả về -1 để báo lỗi
    }

    float ketQua = (float)sum / count;  // Ép kiểu sum thành float trước khi chia
    printf("\nTrung bình %d số nguyên tố trong ma trận là: %.3f", count, ketQua);
    return ketQua;
}

int main() {
    int n, m; // Khai báo số dòng và số cột
    printf("Nhập số dòng và cột: ");
    scanf("%d%d", &n, &m);

    // Cấp phát bộ nhớ động cho ma trận
    int *arr = (int *)malloc(n * m * sizeof(int));
    if (arr == NULL) { // Kiểm tra cấp phát có thành công không
        printf("Lỗi cấp phát bộ nhớ.");
        return 1;
    }

    nhap(arr, n, m); // Gọi hàm nhập ma trận
    xuat(arr, n, m); // Gọi hàm xuất ma trận
    trungBinhSoNguyenTo(arr, n, m); // Tính trung bình số nguyên tố

    free(arr); // Giải phóng bộ nhớ sau khi sử dụng xong
    return 0;
}
