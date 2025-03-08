#include <stdio.h> 
#include <stdlib.h>

// Bài 400: Xóa một hàng trong ma trận

void nhapMaTran(int **arr2, int n, int m) {
    *arr2 = (int*) malloc(n * m * sizeof(int));
    if (*arr2 == NULL) {
        printf("\nLỗi cấp phát."); 
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Nhập phần tử dòng %d cột %d: ", i + 1, j + 1);
            scanf("%d", &(*arr2)[i * m + j]);
        }
    }
}

void xuatMaTran(int *arr1, int n, int m) {
    printf("\nMa trận là: \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d", arr1[i * m + j]);
        }
        printf("\n");
    }
}

void xoaHang(int **arr2, int *n, int m, int x) {
    int *arr1 = (int*) malloc((*n - 1) * m * sizeof(int));
    if (arr1 == NULL) {
        printf("\nLỗi cấp phát."); 
        exit(1);
    }

    int k = 0;
    for (int i = 0; i < *n; i++) {
        if (i == x) continue; // Bỏ qua hàng x
        for (int j = 0; j < m; j++) {
            arr1[k++] = (*arr2)[i * m + j];
        }
    }

    free(*arr2);
    *arr2 = arr1;
    (*n)--;
}

int main() {
    int n, m; 
    printf("Nhập số hàng (n) và số cột (m): "); 
    scanf("%d %d", &n, &m);

    int *arr = NULL;
    nhapMaTran(&arr, n, m);
    xuatMaTran(arr, n, m);

    int x;
    printf("Nhập dòng muốn xóa (từ 0 đến %d): ", n - 1);
    scanf("%d", &x);

    if (x < 0 || x >= n) {
        printf("Lỗi: Dòng nhập không hợp lệ.\n");
    } else {
        xoaHang(&arr, &n, m, x);
        xuatMaTran(arr, n, m);
    }

    free(arr);
    return 0;
}
