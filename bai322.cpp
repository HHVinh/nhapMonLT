// Bài 322: Tính tổng các giá trị trên 1 dòng trong ma trận các số thực
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

float tong1Dong(float *arr, int n, int m){
    float sum = 0;
    int k;
    do{
        printf("\nNhập dòng muốn tính (từ 0 đến %d): ", n-1);
        scanf("%d",&k);
        if(k < 0 || k >= n){
            printf("Lỗi: Dòng phải nằm trong khoảng từ 0 đến %d. Vui lòng nhập lại!\n", n - 1);
        }
    }while(k < 0 || k >= n);

    for(int i = k * (m); i < (k+1) * m; i++){
            sum += arr[i];
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
    
    float ketQua = tong1Dong(arr,n,m);
    printf("\nTổng trên dòng là: %8.2f", ketQua);

    free(arr);
    return 0;
}