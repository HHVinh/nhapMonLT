// Bài 386: Liệt kê các cột có tổng nhỏ nhất
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

void timTongTrenCotNhoNhat(int *arr, int n, int m){
    int *tongCot = (int*) calloc(m, sizeof(int));
    if(tongCot == NULL){
        printf("Lỗi cấp phát.\n");
        exit(1);
    }

    int tongMin = INT_MAX;

    // Tính tổng từng cột
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tongCot[i] += arr[j * m + i];
        }
        if(tongCot[i] < tongMin)
            tongMin = tongCot[i];
    }

    // Thông báo cột nào có tổng nhỏ nhất
    printf("\nCác cột có tổng nhỏ nhất là: ");
    for(int i = 0; i < m; i++){
        if(tongCot[i] == tongMin){
            printf("%d ", i);
        }
    }
    printf("\n");

    // In ra nội dung các cột theo kiểu ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tongCot[j] == tongMin){
                printf("%5d", arr[i * m + j]);
            }
        }
        printf("\n");
    }

    free(tongCot);
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

    timTongTrenCotNhoNhat(arr,n,m);

    free(arr);
    return 0;

}

