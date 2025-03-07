#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>  // Thêm thư viện để sử dụng kiểu bool

// Bài 275: Xóa tất cả các số chính phương trong mảng

void nhapMang(int **arr2, int *n) {
    *arr2 = (int*) malloc(*n * sizeof(int));
    if (*arr2 == NULL) {
        printf("Lỗi cấp phát bộ nhớ."); 
        exit(1);
    }
    for (int i = 0; i < *n; i++) {
        printf("Nhập phần tử %d: ", i + 1);
        scanf("%d", &(*arr2)[i]);
    }
}

void xuatMang(int *arr1, int n) {
    printf("Mảng là: ");
    for (int i = 0; i < n; i++) {
        printf("%3d ", arr1[i]);  // Xuất cách nhau 3 khoảng trắng
    }
    printf("\n");
}

bool soChinhPhuong(int a) {
    if (a < 0) {
        return false;
    }
    int n = sqrt(a);
    return (n * n == a);
}

// Xóa tất cả số chính phương trong mảng
void xoaSoChinhPhuong(int **arr2, int *n) {
    int count = 0;
    for (int i = 0; i < *n; i++) {
        if (soChinhPhuong((*arr2)[i])) {  // Kiểm tra giá trị trong mảng
            count++;
        }
    }

    if (count == 0) {
        printf("\nKhông có số chính phương trong mảng\n");
        return;  // Không cần thoát chương trình
    }

    int *arr1 = (int*) malloc((*n - count) * sizeof(int));
    if (arr1 == NULL) {
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < *n; i++) {
        if (!soChinhPhuong((*arr2)[i])) {  // Giữ lại phần tử không phải số chính phương
            arr1[j++] = (*arr2)[i];
        }
    }

    free(*arr2);
    *arr2 = arr1;
    (*n) -= count;
}

int main() {
    int n; 
    printf("Nhập n: "); 
    scanf("%d", &n);

    int *arr = NULL;
    nhapMang(&arr, &n);
    xuatMang(arr, n);

    xoaSoChinhPhuong(&arr, &n);
    
    printf("Sau khi xóa các số chính phương:\n");
    xuatMang(arr, n);

    free(arr);
    return 0;
}
