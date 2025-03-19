// Bài 327: Tính tổng các giá trị nằm trên biên của ma trận
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

int tongBien(int *arr, int n, int m){
    int tong = 0;

    // Cộng hàng đầu tiên
    for(int i = 0; i < m; i++){
        tong += arr[i];
    }

    // Cộng hàng cuối cùng (nếu có nhiều hơn 1 hàng)
    if (n > 1) {
        for(int i = (n-1) * m; i < n * m; i++){
            tong += arr[i];
        }
    }

    // Cộng cột đầu tiên và cột cuối cùng (bỏ hàng đầu và hàng cuối tránh trùng lặp)
    for(int i = 1; i < n-1; i++){
        tong += arr[i * m];         // Cột đầu tiên
        tong += arr[i * m + (m-1)]; // Cột cuối cùng
    }

    return tong;
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

    int ketQua = tongBien(arr, n, m);
    printf("\nTổng các giá trị trên biên của ma trận là: %d", ketQua);

    free(arr);
    return 0;
}