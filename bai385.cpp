// Bài 385: Liệt kê các dòng có tổng lớn nhất
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0) printf("\n");
    }
}

void timTongTrenDongLonNhat(int *arr, int n, int m){
    int *tongDong = (int*) calloc(n, sizeof(int));
    if(tongDong == NULL){
        printf("Lỗi cấp phát.\n");
        exit(1);
    }

    int tongMax = INT_MIN;

    // Tính tổng từng dòng
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tongDong[i] += arr[i * m + j];
        }
        if(tongDong[i] > tongMax)
            tongMax = tongDong[i];
    }

    printf("\nCác dòng có tổng lớn nhất là: ");
    for(int i = 0; i < n; i++){
        if(tongDong[i] == tongMax){
            printf("\nDòng %d (Tổng = %d): ", i, tongMax);
            for(int j = 0; j < m; j++){
                printf("%5d", arr[i * m + j]);
            }
        }
    }

    free(tongDong);
}


int main(){
    int n, m;
    printf("Nhập số dòng và cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\nMa trận vừa nhập:\n");
    xuat(arr, n, m);

    timTongTrenDongLonNhat(arr,n,m);

    free(arr);
    return 0;

}
