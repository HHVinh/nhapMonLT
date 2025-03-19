// Bài 329: Hãy biến đổi ma trận bằng cách thay các giá trị âm bằng trị tuyệt đối của nó
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

void thayGiaTriAm(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        arr[i] = abs(arr[i]);
    }
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

    thayGiaTriAm(arr,n,m);
    printf("\nSau khi thay các giá trị âm bằng abs thì ");
    xuat(arr,n,m);

    free(arr);
    return 0;
}