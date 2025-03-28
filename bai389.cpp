// Bài 389: Liệt kê các dòng có nhiều số hoàn thiện nhất
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

// Tìm số hoàn thiện
int kiemTraSoHoanThien(int a){
    int tong = 0;
    for(int i = 1; i <= a/2; i++){
        if(a % i == 0){
            tong += i;
        }
    }
    return (tong == a) ? 1 : 0;
}

// Hàm tìm và liệt kê các dòng có nhiều số hoàn thiện nhất
void timDongNhieuSoHoanThienNhat(int *arr, int n, int m){
    int *soLuongSoHoanThien1Dong = (int*) calloc(n, sizeof(int));
    if(soLuongSoHoanThien1Dong == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    int soLuongSoHoanThienMax = 0;

    // Đếm số hoàn thiện từng dòng
    for(int i = 0; i < n; i++){
        int dem = 0;
        for(int j = 0; j < m; j++){
            if(kiemTraSoHoanThien(arr[i * m + j])){
                dem++;
            }
        }
        soLuongSoHoanThien1Dong[i] = dem;
        if(dem > soLuongSoHoanThienMax){
            soLuongSoHoanThienMax = dem;
        }
    }

    // Trường hợp không có số hoàn thiện nào
    if(soLuongSoHoanThienMax == 0){
        printf("\nKhông có số hoàn thiện nào trong ma trận.\n");
        free(soLuongSoHoanThien1Dong);
        return;
    }

    // Đếm số dòng đạt max
    int demDong = 0;
    for(int i = 0; i < n; i++){
        if(soLuongSoHoanThien1Dong[i] == soLuongSoHoanThienMax){
            demDong++;
        }
    }

    printf("\nCó %d dòng có nhiều số hoàn thiện nhất (tổng %d số hoàn thiện):\n", demDong, soLuongSoHoanThienMax);

    // In ra các dòng có nhiều số hoàn thiện nhất
    for(int i = 0; i < n; i++){
        if(soLuongSoHoanThien1Dong[i] == soLuongSoHoanThienMax){
            printf("Dòng %d: ", i);
            for(int j = 0; j < m; j++){
                printf("%5d", arr[i * m + j]);
            }
            printf("\n");
        }
    }

    free(soLuongSoHoanThien1Dong);
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

    timDongNhieuSoHoanThienNhat(arr, n, m);

    free(arr);
    return 0;
}


