#include <stdio.h>
#include <stdlib.h>
//	Bài 272: Hãy xóa tất cả số lớn nhất trong mảng các số thực

void nhapMang(float **arr2, int *n){
    *arr2 = (float*) malloc((*n) * sizeof(float));
    if( *arr2 == NULL){
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }
    for(int i = 0; i < *n; i++){
        printf("Nhập phần tử %d: ", i+1);
        scanf("%f", &(*arr2)[i]);
    }
}

void xuatMang(float *arr1, int n){
    printf("\nMảng là: ");
    for(int i = 0; i < n; i++){
        printf("%6.2f", arr1[i]); // In số thực với 2 chữ số thập phân, cách nhau 3 ký tự
    }
}

void xoaPhanTuMax(float **arr2, int *n) {
    // Tìm giá trị lớn nhất trong mảng
    int max = (*arr2)[0];
    for (int i = 1; i < *n; i++) {
        if ((*arr2)[i] > max) {
            max = (*arr2)[i];
        }
    }

    // Đếm số phần tử lớn nhất
    int count = 0;
    for (int i = 0; i < *n; i++) {
        if ((*arr2)[i] == max) {
            count++;
        }
    }

    // Cấp phát bộ nhớ cho mảng mới
    float *arr1 = (float*) malloc((*n - count) * sizeof(float));
    if (arr1 == NULL) {
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }

    // Sao chép phần tử không phải max vào mảng mới
    int j = 0;
    for (int i = 0; i < *n; i++) {
        if ((*arr2)[i] != max) {
            arr1[j++] = (*arr2)[i];
        }
    }

    // Giải phóng mảng cũ và cập nhật con trỏ
    free(*arr2);
    *arr2 = arr1;
    *n -= count;
}

int main(){
    
    int n; printf("Nhập n: "); scanf("%d", &n);
    float *arr = NULL;
    nhapMang(&arr, &n);
    xuatMang(arr, n);
    xoaPhanTuMax(&arr, &n);
    printf("\nSau khi xóa các phần tử cao nhất: ");
    xuatMang(arr, n);

    free(arr);
    return 0;
}