// Viết hàm tạo mảng động gồm n số nguyên, nhập giá trị từ người dùng, sau đó tìm phần tử lớn thứ 2 trong mảng
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>  // Để dùng INT_MIN

int timPhanTuLonThuHai(int* arr, int n) {
    if (n < 2) {
        printf("Không tồn tại giá trị lớn thứ 2\n");
        return -1;
    }

    int max1 = INT_MIN;
    int max2 = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] > max1) {
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] > max2 && arr[i] != max1) {
            max2 = arr[i];
        }
    }

    if (max2 == INT_MIN) {
        printf("Không tồn tại giá trị lớn thứ 2 (tất cả phần tử đều bằng nhau?)\n");
        return -1;
    }

    return max2;
}

int main() {
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Số lượng phần tử không hợp lệ.\n");
        return 1;
    }

    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int kq = timPhanTuLonThuHai(arr, n);
    if (kq != -1) {
        printf("Phần tử lớn thứ hai là: %d\n", kq);
    }

    free(arr);
    return 0;
}
