#include <stdio.h>
#include <stdlib.h>
//	Bài 270: Nhập mảng sau khi nhập xong đã tự sắp xếp tăng dần

void nhapMangTang( int **arr2, int *n){
    *arr2 = (int*) malloc(*n * sizeof(int));
    if( *arr2 == NULL){
        printf("Lỗi cấp phát!"); exit(1);
    }
    for(int i = 0; i < *n ; i++){
        printf("Nhập phần tử %d: ", i+1);
        scanf("%d", &(*arr2)[i]);
    }
    for(int i = 0; i < *n-1; i++){
        for(int j = i+1; j < *n; j++){
            if((*arr2)[i] > (*arr2)[j]){
                int temp = (*arr2)[i];
                (*arr2)[i] = (*arr2)[j];
                (*arr2)[j] = temp;
            }
        }
    }
}

void xuatMang(int *arr1, int n){
    printf("\nMảng là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", arr1[i]);
    }
}

int main(){
    int n; printf("Nhập n: ");scanf("%d", &n);
    int * arr = NULL;
    nhapMangTang(&arr, &n);
    xuatMang(arr,n);

    free(arr);
    return 0;
}