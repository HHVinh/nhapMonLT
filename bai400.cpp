// Bài 400: Xóa 1 dòng trong ma trận

#include <stdio.h>
#include <stdlib.h>

void nhapMT(int *arr, int n, int m){
    for(int i = 0; i< n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuatMT(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0){
            printf("\n");
        }
    }
}

// void xoaDongTrongMTConTroCap2(int **arr, int *n, int m){
//     int k;
//     do{
//         printf("\nNhập dòng bạn muốn xóa từ 0 đến %d: ", *n-1);
//         scanf("%d", &k);
//         if(k < 0 || k >= *n){
//             printf("Số dòng không phù hợp.");
//         }
//     } while(k < 0 || k >= *n);

//     int *temp = (int*) malloc((*n-1) * m * sizeof(int));
//     if(temp == NULL){
//         printf("Lỗi cấp phát bộ nhớ."); exit(1);
//     }

//     int j = 0;
//     for(int i = 0; i < *n * m; i++){
//         int dongHienTai = i / m;
//         if(dongHienTai != k){
//             temp[j++] = (*arr)[i];
//         }
//     }

//     free(*arr);
//    *arr = temp;
//     (*n)--;
// }

int* xoaDongTrongMTConTroCap1(int *arr, int *n, int m){
    int k;
    do{
        printf("\nNhập dòng bạn muốn xóa từ 0 đến %d: ", *n-1);
        scanf("%d", &k);
        if(k < 0 || k >= *n){
            printf("Số dòng không phù hợp.");
        }
    } while(k < 0 || k >= *n);

    int *temp = (int*) malloc((*n-1) * m * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }
 
    int j = 0;
    for(int i = 0; i < *n * m; i++){
        int dongHienTai = i / m;
        if(dongHienTai != k){
            temp[j++] = arr[i];
        }
    }

    free(arr);
    (*n)--;
    return temp;
}

int main(){

    int n, m; printf("Nhập nxm: "); scanf("%d%d", &n,&m);

    int *arr = (int*) malloc(n * m *sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ."); exit(1);
    }

    nhapMT(arr,n,m);
    printf("\nMa trận vừa nhập là: \n");
    xuatMT(arr,n,m);

    // xoaDongTrongMTConTroCap2(&arr,&n,m);
    // printf("\nMa trận vừa xóa dòng con trỏ C2 là: \n");
    // xuatMT(arr,n,m);

    arr = xoaDongTrongMTConTroCap1(arr,&n,m);
    printf("\nMa trận vừa xóa dòng con trỏ C1 là: \n");
    xuatMT(arr,n,m);

    return 0;
}