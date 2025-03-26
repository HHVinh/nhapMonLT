// Bài 367: Tìm max trong ma trận đặt lính canh)
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0){
            printf("\n");
        }
    }
}

int timMax(int *arr, int n, int m){
    int size = n*m;
    arr[size] = INT_MIN;
    int max = arr[0];
    int i = 1;
    while(arr[i] != INT_MIN){
        if(arr[i] > max){
            max = arr[i];
        }
        i++;
    }
    return max;
}

int main(){

    int n, m;
    printf("Nhập số dòng và cột: "); scanf("%d%d", &n,&m);

    int *arr = (int*) malloc((n*m +1) *sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\n Ma trận vừa nhập là: \n");
    xuat(arr, n, m);

    int ketQua = timMax(arr, n,m);
    
    printf("\n Số lớn nhất trong ma trận là %d.", ketQua);

    free(arr);
    return 0;
}

