// Bài 393: Hoán vị 2 cột trên ma trận
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

int hoanVi2Cot(int *arr, int n, int m){
    if(m < 2){
        printf("Không thể hoán vị khi chỉ có 1 cột.");
        return 0;
    }

    int x, y;
    printf("Nhập vị trí cột thứ 1: "); scanf("%d", &x);
    printf("Nhập vị trí cột thứ 2: "); scanf("%d", &y);

    if(x < 0 || x > m-1 || y < 0 || y > m-1){
        printf("Giá trị 2 cột phải từ 0 đến %d", m-1);
        return 0;
    }

    if(x == y){
        printf("2 vị trí cột trùng nhau nên không cần hoán vị.");
        return 0;
    }

    for(int i = 0; i < n; i++){
        int temp = arr[i * m + x];
        arr[i * m + x] = arr[i * m + y];
        arr[i * m + y] = temp;
    }
    return 1;
}

int main(){

    int n,m; printf("Nhập số dòng (n) và số cột (m): ");scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m *sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ"); exit(1);
    }

    nhap(arr,n,m);
    printf("\nMa trận vừa nhập là: \n");
    xuat(arr,n,m);

    if(hoanVi2Cot(arr,n,m)){
        printf("\nMa trận vừa hoán vị 2 cột là: \n");
        xuat(arr,n,m);
    }

    free(arr);
    return 0;
}