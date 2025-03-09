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

// Hàm tìm max và min trong mảng
void timMinMax(int *arr1, int n, int *minValue, int *maxValue) {
    *minValue = arr1[0];
    *maxValue = arr1[0];
    for (int i = 1; i < n; i++) {
        if (arr1[i] < *minValue) *minValue = arr1[i];
        if (arr1[i] > *maxValue) *maxValue = arr1[i];
    }
}

// Hàm xóa phần tử xuất hiện nhiều hơn 1 lần
void xoaPhanTuXuatHienHon1Lan(int *arr1, int *n) {
    if (*n == 0) return;

    int minValue, maxValue;
    timMinMax(arr1, *n, &minValue, &maxValue);

    int range = maxValue - minValue + 1; // Dải giá trị cần xử lý

    // Cấp phát mảng tần số
    int *tanSo = (int*) calloc(range, sizeof(int));
    if (tanSo == NULL) {
        printf("Lỗi cấp phát bộ nhớ."); free(arr1); exit(1);
    }

    // Đếm tần số xuất hiện
    for (int i = 0; i < *n; i++) {
        tanSo[arr1[i] - minValue]++; // Dịch giá trị âm thành chỉ số không âm
    }

    // Ghi lại các phần tử xuất hiện đúng 1 lần
    int j = 0;
    for (int i = 0; i < *n; i++) {
        if (tanSo[arr1[i] - minValue] == 1) {
            arr1[j++] = arr1[i];
        }
    }

    free(tanSo);
    *n = j; // Cập nhật lại số phần tử
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
