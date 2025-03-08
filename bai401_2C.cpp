#include <stdio.h> 
#include <stdlib.h>

// Bài 401: Xóa một cột trong ma trận

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

void xoaCot(int **arr2, int n, int *m, int x) {
    if (*m <= 1) {
        printf("Không thể xóa thêm cột!\n");
        return;
    }

    int *arr1 = (int*) malloc(n * (*m - 1) * sizeof(int));
    if (arr1 == NULL) {
        printf("\nLỗi cấp phát."); 
        exit(1);
    }

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < *m; j++) {
            if (j == x) continue; // Bỏ qua cột x
            arr1[k++] = (*arr2)[i * (*m) + j];
        }
    }

    free(*arr2);
    *arr2 = arr1;
    (*m)--;
}

int main() {
    int n, m; 
    printf("Nhập số hàng (n) và số cột (m): "); 
    scanf("%d %d", &n, &m);

    if (n <= 0 || m <= 0) {
        printf("Lỗi: Kích thước không hợp lệ.\n");
        return 1;
    }

    int *arr = NULL;
    nhapMaTran(&arr, n, m);
    xuatMaTran(arr, n, m);

    int x;
    printf("\nNhập cột muốn xóa (từ 0 đến %d): ", m - 1);
    scanf("%d", &x);

    if (x < 0 || x >= m) {
        printf("Lỗi: Cột nhập không hợp lệ.\n");
    } else {
        xoaCot(&arr, n, &m, x);
        xuatMaTran(arr, n, m);
    }

    free(arr);
    return 0;
}
