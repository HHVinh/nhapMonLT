// Bài 392: Hoán vị 2 dòng trên ma trận
#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("%5d", arr[i]);
        if((i + 1) % m == 0){
            printf("\n");
        }
    }
}

int hoanVi2Dong(int *arr, int n, int m){
    if(n < 2){
        printf("Ma trận chỉ có 1 dòng, không thể hoán vị.\n");
        return 0;
    }

    int x, y;
    printf("Nhập dòng thứ nhất cần hoán vị (0 đến %d): ", n - 1); scanf("%d", &x);
    printf("Nhập dòng thứ hai cần hoán vị (0 đến %d): ", n - 1); scanf("%d", &y);

    if(x < 0 || x >= n || y < 0 || y >= n){
        printf("Giá trị dòng không hợp lệ.\n");
        return 0;
    }

    if(x == y){
        printf("Hai dòng giống nhau, không cần hoán vị.\n");
        return 0;
    }

    for(int j = 0; j < m; j++){
        int temp = arr[x * m + j];
        arr[x * m + j] = arr[y * m + j];
        arr[y * m + j] = temp;
    }

    return 1;
}

int main(){
    int n, m;
    printf("Nhập số dòng (n) và số cột (m) của ma trận: ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ!\n");
        return 1;
    }

    nhap(arr, n, m);

    printf("\nMa trận vừa nhập là:\n");
    xuat(arr, n, m);

    if(hoanVi2Dong(arr, n, m)){
        printf("\nMa trận sau khi hoán vị:\n");
        xuat(arr, n, m);
    }

    free(arr);
    return 0;
}
