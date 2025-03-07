#include <stdio.h>
#include <stdlib.h>
//	Bài 273: Xóa tất cả các số âm trong mảng

void nhapMang(int **arr2, int *n){
    *arr2 = (int*) malloc(*n * sizeof(int));
    if(*arr2 == NULL){
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }
    for(int i = 0; i < *n; i++){
        printf("Nhập phần tử %d: ", i+1);
        scanf("%d", &(*arr2)[i]);
    }
}

void xuatMang(int *arr1, int n){
    printf("\nMảng là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", arr1[i]);
    }
    printf("\n");
}

void xoaPhanTuAm(int **arr2, int *n){
    int count = 0;
    for(int i = 0; i < *n; i++){
        if((*arr2)[i] < 0){
            count++;
        }
    }
    
    int *arr1 = (int*) malloc((*n - count) * sizeof(int));
    if(arr1 == NULL){
        printf("Lỗi cấp phát."); exit(1);
    }

    int j = 0;
    for(int i = 0; i < *n; i++){
        if((*arr2)[i] > 0){
            arr1[j++] = (*arr2)[i];
        }
    }

    free(*arr2); *arr2 = arr1; *n -= count;
}

int main(){

    int n; printf("Nhập n: "); scanf("%d", &n);
    int *arr = NULL;
    nhapMang(&arr, &n);
    xuatMang(arr, n);
    xoaPhanTuAm(&arr, &n);
    printf("Xóa phần tử âm");
    xuatMang(arr, n);

    free(arr);
    return 0;
}