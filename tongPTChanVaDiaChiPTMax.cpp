// Viết hàm:
// •	Tính tổng các phần tử chẵn trong mảng.
// •	Xuất địa chỉ của phần tử lớn nhất.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int tinhTongVaDiaChi(int* arr, int n) {
    int tong = 0;          // Tính tổng các số chẵn
    int coPTChan = 0;      // Để kiểm tra có số chẵn không

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            tong += arr[i];
            coPTChan = 1;
        }
    }

    if (!coPTChan) {
        printf("Không có phần tử chẵn trong mảng\n");
        return 0; // Không thực hiện tìm phần tử lớn nhất nếu không có số chẵn
    }

    int max = INT_MIN;  // Khởi tạo giá trị lớn nhất là nhỏ nhất có thể
    int* diaChiMax = NULL; // Địa chỉ của phần tử lớn nhất

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0 && arr[i] > max ) {
            max = arr[i];
            diaChiMax = &arr[i]; // Lưu địa chỉ của phần tử lớn nhất
        }
    }

    printf("Tổng các số chẵn: %d\n", tong);
    printf("Phần tử lớn nhất: %d\n", max);
    printf("Địa chỉ phần tử lớn nhất: %p\n", (void*)diaChiMax);

    return tong;
}

int main() {
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Không đủ bộ nhớ\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhập phần tử thứ %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    tinhTongVaDiaChi(arr, n);

    free(arr);
    return 0;
}
