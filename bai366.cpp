// Bài 366: Tìm số chẵn đầu tiên trong ma trận (đặt lính canh)
#include <stdio.h>
#include <stdlib.h>

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

int timSoChanDauTien(int *arr, int n, int m){
    int *temp = (int*) malloc((n*m+1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    for(int i = 0; i < n*m; i++){
        temp[i] = arr[i];
    }

    temp[n*m] = 0;
    int i = 0;
    while(temp[i] % 2 != 0) i++;
    if(i < n*m){
        int ketQua = temp[i];
        free(temp);
        return ketQua;
    } else{
        free(temp);
        return -1;
    }
}

int main(){

    int n, m;
    printf("Nhập số dòng và cột: "); scanf("%d%d", &n,&m);

    int *arr = (int*) malloc(n*m *sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\n Ma trận vừa nhập là: \n");
    xuat(arr, n, m);

    int ketQua = timSoChanDauTien(arr, n,m);
    if(ketQua == -1){
        printf("\n Không có số chẵn nào trong ma trận.");
    } else{
        printf("\n Số chẵn đầu tiên trong ma trận là: %d", ketQua);
    }

    free(arr);
    return 0;
}
