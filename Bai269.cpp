#include <stdio.h>
#include <stdlib.h>
//  Bài 269: Thêm x vào trong mảng tăng nhưng vẫn giữ nguyên tính tăng của mảng
// Nhập mảng và sắp xếp tăng dần
void nhapMang(int **arr, int *n) {
    *arr = (int*) malloc((*n) * sizeof(int));
    if (*arr == NULL) {
        printf("Lỗi cấp phát\n");
        exit(1);
    }

    for (int i = 0; i < *n; i++) {
        printf("Nhập phần tử %d: ", i + 1);
        scanf("%d", &(*arr)[i]);
    }

    // Sắp xếp mảng tăng dần (Bubble Sort)
    for (int i = 0; i < (*n) - 1; i++) {
        for (int j = i + 1; j < *n; j++) {
            if ((*arr)[i] > (*arr)[j]) {
                int temp = (*arr)[i];
                (*arr)[i] = (*arr)[j];
                (*arr)[j] = temp;
            }
        }
    }
}

// Xuất mảng
void xuatMang(int *arr, int n) {
    printf("\nMảng là: ");
    for (int i = 0; i < n; i++) {
        printf("%3d", arr[i]);
    }
    printf("\n");
}

// Chèn phần tử vào mảng tăng dần
void themPhanTu(int **arr, int *n, int value) {
    int *arr1 = (int*) malloc((*n + 1) * sizeof(int));
    if (arr1 == NULL) {
        printf("\nLỗi cấp phát\n");
        exit(1);
    }

    // Tìm vị trí chèn
    int k = *n;
    for (int i = 0; i < *n; i++) {
        if (value < (*arr)[i]) {
            k = i;
            break;
        }
    }

    // Chèn phần tử vào vị trí k
    for (int i = 0; i < k; i++) {
        arr1[i] = (*arr)[i];
    }
    arr1[k] = value;
    for (int i = k; i < *n; i++) {
        arr1[i + 1] = (*arr)[i];
    }

    // Giải phóng mảng cũ và cập nhật con trỏ
    free(*arr);
    *arr = arr1;
    (*n)++;
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);

    int *arr = NULL;
    nhapMang(&arr, &n);
    xuatMang(arr, n);

    int value;
    printf("\nNhập value: ");
    scanf("%d", &value);

    themPhanTu(&arr, &n, value);
    printf("\nThêm %d vào mảng", value);
    xuatMang(arr, n);

    free(arr);
    return 0;
}
