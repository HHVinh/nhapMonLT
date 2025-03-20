// Bài 357: Liệt kê các dòng có chứa số nguyên tố trong ma trận các số nguyên
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

int kiemTraSoNguyenTo(int a) {
    if (a < 2) return 0; // Số nhỏ hơn 2 không phải số nguyên tố

    for (int i = 2; i * i <= a; i++) { // Kiểm tra đến căn bậc hai của a
        if (a % i == 0) {
            return 0; // Nếu chia hết thì không phải số nguyên tố
        }
    }

    return 1; // Nếu không chia hết cho số nào thì là số nguyên tố
}

void kiemTraDongToanSoNguyenTo(int *arr, int n, int m) {
    int coDongNguyenTo = 0;  // Biến kiểm tra có dòng toàn số NT hay không?
    int giaTriDau = 1; // Đánh dấu lần đầu in

    for (int i = 0; i < n; i++) {
        int flag = 1;  // Đặt lại cờ cho từng dòng

        for (int j = 0; j < m; j++) {
            if (!kiemTraSoNguyenTo(arr[i * m + j])) { // Nếu có số không phải số nguyên tố
                flag = 0;
                break;
            }
        }

        if (flag) {
            if(!giaTriDau){
                printf(", "); // Chỉ in dấu phẩy khi không phải số đầu
            }
            printf("%d", i);
            coDongNguyenTo = 1;
            giaTriDau = 0;
        }
    }

    if (!coDongNguyenTo) {
        printf("Không có dòng nào toàn số nguyên tố.");
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

    printf("\nCác dòng toàn số nguyên tố trong ma trận là: ");
    kiemTraDongToanSoNguyenTo(arr, n, m);

    free(arr);
    return 0;
}
