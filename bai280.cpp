//	Bài 280: Hãy đưa số 1 về đầu mảng có giữ nguyên vị trí
#include <stdio.h>
#include <stdlib.h>

void nhap(int **arr2, int n){
    *arr2 = (int*) malloc(n * sizeof(int));
    if(*arr2 == NULL){
        printf("\nLỗi cấp phát bộ nhớ."); exit(1);
    }
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử A[%d]: ", i+1);
        scanf("%d", &(*arr2)[i]);
    }
}

void xuat(int *arr, int n){
    printf("\nMảng là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", arr[i]);
    }
}

void duaSo1VeDauMangGiuNguyenViTri(int **arr2, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        if((*arr2)[i] == 1){
            count++;
        }
    }
    if(count == 0){
        printf("\nMảng không có số 1.");
        return;
    }
    int j = 0;
    int *arr = (int*) malloc(n * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }
    for(int i = 0; i < n; i++){
        if((*arr2)[i] == 1){
            arr[j++] = (*arr2)[i];
        }
    }
    for(int i = 0; i < n; i++){
        if((*arr2)[i] != 1){
            arr[j++] = (*arr2)[i];
        }
    }
    free(*arr2);
    *arr2 = arr;
}

int main() {
    int n;
    printf("Nhập n: ");
    scanf("%d", &n);
    int *arr;

    nhap(&arr, n);
    xuat(arr, n);
    
    printf("\nSau khi đưa số 1 về đầu giữ nguyên vị trí:");
    duaSo1VeDauMangGiuNguyenViTri(&arr, n);
    xuat(arr, n);

    free(arr);
    return 0;
}
