// Bài 333: Tính tổng các số hoàn thiện trong ma trận các số nguyên
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

int kiemTraSoHoanThien(int a){
    int tong = 0;
    for(int i = 1; i <= a/2; i++){
        if(a % i == 0){
            tong += i;
        }
    }
    return (tong == a) ? 1 : 0;
}

int tongSoHoanThien(int *arr, int n, int m){
    int tong = 0; int count = 0;
    for(int i = 0; i < n*m; i++){
        if(kiemTraSoHoanThien(arr[i])){
            tong += arr[i];
            count ++;
        }
    }

    return (count > 0)  ? tong : 0;
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

    int ketQua = tongSoHoanThien(arr,n,m);

    if(ketQua == 0){
        printf("\nKhông có số hoàn thiện nào.");
    }
    else{
        printf("\nTổng các số hoàn thiện là: %d", ketQua);
    }

    free(arr);
    return 0;
}