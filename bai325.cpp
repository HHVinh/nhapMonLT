// Bài 325: Tính tích các số chẵn trên 1 cột trong ma trận các số nguyên
#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

int tichSoChan1Cot(int *arr, int n, int m, int k){
    
    int tich = 1;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i * m + k] % 2 == 0){
            tich *= arr[i * m + k];
            count ++;
        }
    }
    return (count > 0) ? tich : 0;
}

int main(){

    int n, m;
    printf("\nNhập số lượng dòng và cột: ");
    scanf("%d%d", &n,&m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr,n,m);
    xuat(arr,n,m);

    int k;
    do{
        printf("\nNhập cột cần tính (từ 0 đến %d): ", m-1);
        scanf("%d", &k);
        if(k >= m || k < 0){
            printf("\nNhập lại cột cần tính: ");
        }
    } 
    while(k >= m || k < 0);

    int ketQua = tichSoChan1Cot(arr,n,m,k);

    if(ketQua == 0){
        printf("\nKhông có số chẵn nào trong cột %d", k);
    }
    else{
        printf("\nTích các số chẵn trong cột %d là: %d", k, ketQua);
    }

    free(arr);
    return 0;
}