// Bài 320: Tính tổng các số dương trong ma trận các số thực
#include <stdio.h>
#include <stdlib.h>

void nhap(float *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%f", &arr[i]);
    }
}

void xuat(float *arr, int n, int m){
    printf("\nMa trận vừa nhập là:\n");
    for(int i = 0; i < n*m; i++){
        printf("%8.2f", arr[i]);
        if((i+1) % m == 0) printf("\n");
    }
}

float tongSoDuong(float *arr, int n, int m){
    float sum = 0;
    for(int i = 0; i< n*m; i++){
        if(arr[i] > 0){
            sum += arr[i];
        }
    }
    return sum;
}

int main(){

    int n, m; printf("\nNhập hàng và cột: "); scanf("%d%d", &n,&m);

    float *arr = (float*) malloc(n*m *sizeof(float));
    if(arr == NULL){
        printf("\nLỗi cấp phát bộ nhớ."); exit(1);
    }

    nhap(arr,n,m);
    xuat(arr,n,m);
    
    float ketQua = tongSoDuong(arr,n,m);
    if(ketQua > 0){
        printf("\nTổng các số dương là: %8.2f", ketQua);
    }
    else{
        printf("\nKhông có số dương nào trong ma trận vừa nhập");
    }

    free(arr);
    return 0;
}