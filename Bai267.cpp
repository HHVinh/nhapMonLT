#include <stdio.h>
#include <stdlib.h>
// Bài 267: Viết hàm nhập mảng sao cho khi nhập xong thì giá trị trong mảng sắp xếp giảm dần

void nhapMang(int **arr, int n){
    *arr = (int*) malloc(n * sizeof(int));
    if( *arr == NULL){
        printf("Lỗi\n"); exit(1);
    }
    for(int i = 0; i < n; i++){
        printf("Nhập p.tử thứ %d: ", i+1);
        scanf("%d", &(*arr)[i]);
    }
    for(int i = 0; i < n-1; i++){
        for(int j = i +1; j < n; j++){
            if((*arr)[i] < (*arr)[j]){
                int temp = (*arr)[i];
                    (*arr)[i] = (*arr)[j];
                    (*arr)[j] = temp;
            }
        }
    }                   
}

void xuatMang(int *arr, int n){
    printf("\nMảng là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", arr[i]);
    }
    printf("\n");
}

// Cách thường là xếp riêng
// void xepMangGiam(int *arr, int n){
//     for(int i = 0; i < n-1; i++){
//         for(int j = i +1; j < n; j++){
//             if(arr[i] < arr[j]){
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
// }

int main(){

    int n; printf("Nhập n: "); scanf("%d", &n);
    int *arr = NULL;

    nhapMang(&arr, n);
    printf("\nMảng sau khi sắp xếp là: ");
    xuatMang(arr, n);
    // xepMangGiam(arr, n);
    // xuatMang(arr, n);

    free(arr);
    return(0);

}