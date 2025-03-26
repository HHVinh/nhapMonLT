// Bài 369: Tìm số dương đầu tiên trong ma trận

#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ",i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d",arr[i]);
        if((i+1) % m == 0){ 
            printf("\n");
        }
    }
}

int timSoDuongDauTien(int *arr, int n, int m){
    int size = n*m;
    int *temp = (int*) malloc((size +1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }

    temp[size] = -1;
    int ketQua;
    int i = 0;
    while(temp[i] <= 0) i++;
    if(i < size){
        ketQua = temp[i];
    } else{
        ketQua = -1;
    }
    free(temp);
    return ketQua;
}

int main(){

    int n, m; printf("Nhập số hàng và cột: ");scanf("%d%d", &n,&m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi."); exit(1);
    }

    nhap(arr,n,m);
    xuat(arr,n,m);

    int ketQua = timSoDuongDauTien(arr, n, m);
    if(ketQua == -1){
        printf("Không có số dương trong ma trận.");
    } else{
        printf("Số dương đầu tiên trong ma trận là: %d", ketQua);
    }

    free(arr);
    return 0;
}