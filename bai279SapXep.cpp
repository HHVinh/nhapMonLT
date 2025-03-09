#include <stdio.h>
#include <stdlib.h>

// Hàm nhập mảng
void nhapMang(int **arr2, int n) {
    *arr2 = (int*) malloc(n * sizeof(int));
    if (*arr2 == NULL) {
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }
    for (int i = 0; i < n; i++) {
        printf("\nNhập phần tử %d: ", i + 1);
        scanf("%d", &(*arr2)[i]);
    }
}

// Hàm xuất mảng
void xuatMang(int *arr1, int n) {
    printf("\nMảng là: ");
    for (int i = 0; i < n; i++) {
        printf("%3d", arr1[i]);
    }
}

// Hàm sắp xếp mảng tăng dần
void sapXepMang(int *arr1, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr1[i] > arr1[j]) {
                int temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
        }
    }
}

// Hàm xóa phần tử xuất hiện nhiều hơn 1 lần
void xoaPhanTuXuatHienHon1Lan(int *arr1, int *n) {
    if (*n <= 1) return; // Nếu mảng có 0 hoặc 1 phần tử, không cần xử lý

    // Sắp xếp mảng trước để dễ kiểm tra phần tử trùng
    sapXepMang(arr1, *n);

    int j = 0;
    if (*n > 1 && arr1[0] != arr1[1]) { // Xử lý phần tử đầu tiên nếu nó không trùng
        arr1[j++] = arr1[0];
    }

    for (int i = 1; i < *n - 1; i++) {
        if (arr1[i] != arr1[i - 1] && arr1[i] != arr1[i + 1]) {
            arr1[j++] = arr1[i];
        }
    }

    // Xử lý phần tử cuối cùng nếu nó không trùng
    if (*n > 1 && arr1[*n - 1] != arr1[*n - 2]) {
        arr1[j++] = arr1[*n - 1];
    }

    *n = j; // Cập nhật lại số phần tử trong mảng
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);

    int *arr = NULL;
    nhapMang(&arr, n);
    xuatMang(arr, n);

    xoaPhanTuXuatHienHon1Lan(arr, &n);

    // Kiểm tra nếu mảng rỗng
    if (n == 0) {
        printf("\nMảng không còn phần tử nào sau khi xóa.");
    } else {
        xuatMang(arr, n);
    }

    free(arr);
    return 0;
}
