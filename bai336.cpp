// Bài 336: Đếm tần suất xuất hiện của 1 giá trị x trong ma trận các số thực
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

float tanSuatXuatHien(float *arr, int n, int m, float k){
    int count = 0;
    for(int i = 0; i < n*m; i++){
        if(arr[i] == k){
            count++;
        }    
    }
    return count;
}

int main(){

    int n, m; printf("\nNhập hàng và cột: "); scanf("%d%d", &n,&m);

    float *arr = (float*) malloc(n*m *sizeof(float));
    if(arr == NULL){
        printf("\nLỗi cấp phát bộ nhớ."); exit(1);
    }

    nhap(arr,n,m);
    xuat(arr,n,m);
    
    float k;
    printf("Nhập phần tử cần đếm: "); scanf("%f", &k);

    int ketQua = tanSuatXuatHien(arr, n, m, k);
    printf("\nTổng trên dòng là: %d", ketQua);

    free(arr);
    return 0;
}