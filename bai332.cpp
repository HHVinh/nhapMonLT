// Bài 332: Tính tổng các giá trị lẻ trên 1 cột của ma trận các số nguyên
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

int tongGiaTriLe1Cot(int *arr, int n, int m, int k){
    int tong = 0; int count = 0;
    for(int i = 0; i < n; i++){
        if(arr[i * m + k] % 2 != 0){
            tong += arr[i * m + k];
            count ++;
        }
    }
    return (count > 0) ? tong : 0;
}

int tongGiaTriLeTrenBien(int *arr, int n, int m){
    int tong = 0;  int count = 0;
    // Tổng hàng đầu
    for(int i = 0; i < m; i++){
        if(arr[i] % 2 != 0){
            tong += arr[i];
            count ++;
        }
    }

    // Tổng hàng cuối
    if(n > 1){
        for(int i = (n-1) * m; i < n * m; i++){
            if(arr[i] % 2 != 0){
                tong += arr[i];
                count ++;
            }
        }
    }

    // Tổng các hàng ở giữa:
    for(int i = 1; i < n-1; i++){
        if(arr[i * m] % 2 != 0){
            tong += arr[i * m]; // Phần tử đầu hàng
            count ++;
        }
        if(arr[i * m + m -1] % 2 != 0){
            tong += arr[i * m + m -1]; // Phần tử cuối hàng
            count ++;
        }
    }

    return (count > 0) ? tong : 0;
}

int main(){

    int n, m; printf("\nNhập số lượng dòng và cột: "); scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("\nLỗi cấp phát bộ nhớ."); exit(1);
    }

    nhap(arr,n,m);
    printf("\nMa trận là: \n");
    xuat(arr,n,m);

    int k;
    do{
        printf("\nNhập cột muốn tính (từ 0 đến %d): ", m-1); scanf("%d", &k);
        if(k >= m || k < 0){
            printf("\nSố cột chưa đúng. Nhập lại k: "); scanf("%d", &k);
        }
    }
    while(k >= m || k < 0);

    int ketQua1 = tongGiaTriLe1Cot(arr,n,m,k);
    if(ketQua1 == 0){
        printf("\nKhông có số lẻ trên cột %d.", k);
    }
    else{
        printf("\nTổng các số lẻ của cột %d là: %d", k, ketQua1);
    }

    int ketQua2 = tongGiaTriLeTrenBien(arr,n,m);
    if(ketQua2 == 0){
        printf("\nKhông có số lẻ trên biên.");
    }
    else{
        printf("\nTổng các số lẻ trên biên là: %d", ketQua2);
    }

    free(arr);
    return 0;
}