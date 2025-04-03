#include <stdio.h>
#include <stdlib.h>

int cong(int a, int b){
    return a + b;
}

int tru(int a, int b){
    return a - b;
}

int laAm(int a){
    return a < 0;
}

int laDuong(int a){
    return a > 0;
}

int laSoNguyenTo(int a) {
    if (a <= 1) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

int timPhanTuDauTien(int *arr, int n, int (*dieuKien)(int)){
    for(int i = 0; i < n; i++){
        if(dieuKien(arr[i])){
            return i;
        }
    }
    return -1;
}

void nhap(int *arr, int n){
    for(int i = 0; i < n; i++){
        printf("Nhập phần tử A[%d]: ", i);
        scanf("%d",arr+i);
    }
}

int main(){

    int (*phepToan) (int, int);

    int a = 100;
    int b = 20;

    phepToan = cong;
    int kq = phepToan(a,b);
    printf("\nKết quả %d + %d = %d",a,b,kq);

    phepToan = tru;
    kq = phepToan(a,b);
    printf("\nKết quả %d - %d = %d",a,b,kq);

    int n; printf("\nNhập n: "); scanf("%d",&n);
    int *arr = (int*) malloc(n * sizeof(int));
    nhap(arr, n);

    int ketQua = timPhanTuDauTien(arr, n, laAm);
    printf("\nPhần tử âm đầu tiên ở vị trí: %d", ketQua);

    ketQua = timPhanTuDauTien(arr, n, laDuong);
    printf("\nPhần tử dương đầu tiên ở vị trí: %d", ketQua);

    ketQua = timPhanTuDauTien(arr, n, laSoNguyenTo);
    printf("\nPhần tử là số nguyên tố đầu tiên ở vị trí: %d", ketQua);

    free(arr);
    return 0;
}