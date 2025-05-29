#include <stdio.h>
#include <stdlib.h>

void xoaSoChan(int** arr, int* n) {
    int demSoLe = 0;

    // Đếm số lẻ
    for (int i = 0; i < *n; i++) {
        if ((*arr)[i] % 2 != 0) {
            demSoLe++;
        }
    }

    if (demSoLe == 0) {
        printf("\nMảng giữ nguyên (không có số lẻ):\n");
        for (int i = 0; i < *n; i++) {
            printf("%5d", (*arr)[i]);
        }
        return;
    }

    int* temp = (int*) malloc(demSoLe * sizeof(int));
    if (temp == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    int k = 0;
    for (int i = 0; i < *n; i++) {
        if ((*arr)[i] % 2 != 0) {
            temp[k++] = (*arr)[i];
        }
    }

    free(*arr);
    *arr = temp;
    *n = demSoLe;

    printf("\nMảng sau khi xóa hết số chẵn là:\n");
    for (int i = 0; i < *n; i++) {
        printf("%5d", (*arr)[i]);
    }
}

int main() {
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n);

    int* arr = (int*) malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhập arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    xoaSoChan(&arr, &n);

    free(arr);
    return 0;
}
