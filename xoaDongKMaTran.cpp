// Viết hàm nhận vào một mảng động 2 chiều int** arr, số dòng n, số cột m, và một dòng k. Xóa dòng k khỏi mảng
#include <stdio.h>
#include <stdlib.h>

void nhapMaTran(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("Nhập dòng %d:\n", i);
        for (int j = 0; j < m; j++) {
            printf("  A[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void xuatMaTran(int** arr, int n, int m) {
    printf("Ma trận hiện tại:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

void xoaDong(int*** arr, int* n, int m, int k) {
    if (k < 0 || k >= *n) {
        printf("Lỗi: vị trí dòng không hợp lệ.\n");
        return;
    }

    free((*arr)[k]);

    if (*n == 1) {
        printf("Đã xóa dòng duy nhất của mảng.\n");
        free(*arr);
        *arr = NULL;
        *n = 0;
        return;
    }

    int** temp = (int**)malloc((*n - 1) * sizeof(int*));
    if (temp == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        return;
    }

    for (int i = 0; i < k; i++) {
        temp[i] = (*arr)[i];
    }
    for (int i = k; i < *n - 1; i++) {
        temp[i] = (*arr)[i + 1];
    }

    free(*arr);
    *arr = temp;
    (*n)--;
}

int main() {
    int n, m;
    printf("Nhập số dòng và số cột của ma trận: ");
    scanf("%d %d", &n, &m);

    int** arr = (int**)malloc(n * sizeof(int*));
    if (arr == NULL) {
        printf("Lỗi cấp phát bộ nhớ dòng.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = (int*)malloc(m * sizeof(int));
        if (arr[i] == NULL) {
            printf("Lỗi cấp phát bộ nhớ cột.\n");
            return 1;
        }
    }

    nhapMaTran(arr, n, m);
    xuatMaTran(arr, n, m);

    int k;
    printf("\nNhập dòng k muốn xóa (0-based): ");
    scanf("%d", &k);

    xoaDong(&arr, &n, m, k);

    if (n > 0) {
        printf("\nMa trận sau khi xóa dòng %d:\n", k);
        xuatMaTran(arr, n, m);
    } else {
        printf("\nMảng hiện tại rỗng.\n");
    }

    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
