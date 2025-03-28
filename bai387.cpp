// Bài 387: Liệt kê các dòng có nhiều số chẵn nhất
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Hàm nhập ma trận
void nhap(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

// Hàm xuất ma trận
void xuat(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("%5d", arr[i]);
        if((i + 1) % m == 0) printf("\n");
    }
}

// Hàm tìm và liệt kê các dòng có nhiều số chẵn nhất
void timDongCoNhieuSoChanNhat(int *arr, int n, int m){
    int *soLuongChanTrenDong = (int*) calloc(n, sizeof(int));
    if(soLuongChanTrenDong == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    int tongSoChanMax = 0;

    // Đếm số chẵn trên từng dòng
    for(int i = 0; i < n; i++){
        int dem = 0;
        for(int j = 0; j < m; j++){
            if(arr[i * m + j] % 2 == 0){
                dem++;
            }
        }
        soLuongChanTrenDong[i] = dem;
        if(dem > tongSoChanMax){
            tongSoChanMax = dem;
        }
    }

    // Trường hợp không có số chẵn nào
    if(tongSoChanMax == 0){
        printf("\nKhông có số chẵn nào trong ma trận.\n");
        free(soLuongChanTrenDong);
        return;
    }

    // Đếm số dòng đạt max
    int demDong = 0;
    for(int i = 0; i < n; i++){
        if(soLuongChanTrenDong[i] == tongSoChanMax){
            demDong++;
        }
    }

    printf("\nCó %d dòng có nhiều số chẵn nhất (tổng %d số chẵn):\n", demDong, tongSoChanMax);

    // In ra các dòng có nhiều số chẵn nhất
    for(int i = 0; i < n; i++){
        if(soLuongChanTrenDong[i] == tongSoChanMax){
            printf("Dòng %d: ", i);
            for(int j = 0; j < m; j++){
                printf("%5d", arr[i * m + j]);
            }
            printf("\n");
        }
    }

    free(soLuongChanTrenDong);
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

    timDongCoNhieuSoChanNhat(arr, n, m);

    free(arr);
    return 0;
}


