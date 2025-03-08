#include <stdio.h>
#include <stdlib.h>
//	Bài 276: Xóa tất cả các phần tử trùng với x

void nhapMang(int ** arr2, int *n){
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
}

void xoaPhanTuX(int ** arr2, int *n, int *x){
    int count = 0;
    for(int i = 0; i < *n; i++){
        if((*arr2)[i] == *x){
            count++;
        }
    }
    if(count == 0){
        printf("\nKhông có phần tử nào được xóa.");
    }
    else{
        int *arr1 = (int*) malloc((*n - count) * sizeof(int));
        if(*arr2 == NULL){
            printf("Lỗi cấp phát bộ nhớ."); exit(1);
        }
        int j =  0;
        for(int i = 0; i < *n; i++){
            if((*arr2)[i] != *x){
                arr1[j++] = (*arr2)[i];
            }
        }
        printf("\nĐã xóa %d phần tử của mảng.", count);
        free(*arr2); *arr2 = arr1; (*n) -= count;
    } 
}

int main(){

    int n; printf("Nhập n: "); scanf("%d", &n);

    int *arr = NULL;
    nhapMang(&arr, &n);
    xuatMang(arr, n);

    int x; printf("\nNhập x: "); scanf("%d", &x);
    xoaPhanTuX(&arr, &n, &x);
    xuatMang(arr, n);

    free(arr);
    return 0;

}