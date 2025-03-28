// Bài 388: Liệt kê các dòng có nhiều số nguyên tố nhất
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

// Tìm số nguyên tố
int kiemTraNguyento(int a){
    if(a < 2) return 0;
    for(int i = 2; i*i <= a; i++){
        if(a % i == 0){
            return 0;
        }
    }
    return 1;
}

// Hàm tìm và liệt kê các dòng có nhiều số nguyên tố nhất
void timDongNhieuSoNguyenToNhat(int *arr, int n, int m){
    int *soLuongSoNguyenTo1Dong = (int*) calloc(n, sizeof(int));
    if(soLuongSoNguyenTo1Dong == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    int soLuongSoNguyenToMax = 0;

    // Đếm số NT từng dòng
    for(int i = 0; i < n; i++){
        int dem = 0;
        for(int j = 0; j < m; j++){
            if(kiemTraNguyento(arr[i * m + j])){
                dem++;
            }
        }
        soLuongSoNguyenTo1Dong[i] = dem;
        if(dem > soLuongSoNguyenToMax){
            soLuongSoNguyenToMax = dem;
        }
    }

    // Trường hợp không có số nguyên tố nào
    if(soLuongSoNguyenToMax == 0){
        printf("\nKhông có số nguyên tố nào trong ma trận.\n");
        free(soLuongSoNguyenTo1Dong);
        return;
    }

    // Đếm số dòng đạt max
    int demDong = 0;
    for(int i = 0; i < n; i++){
        if(soLuongSoNguyenTo1Dong[i] == soLuongSoNguyenToMax){
            demDong++;
        }
    }

    printf("\nCó %d dòng có nhiều số nguyên tố nhất (tổng %d số nguyên tố):\n", demDong, soLuongSoNguyenToMax);

    // In ra các dòng có nhiều số nguyên tố nhất
    for(int i = 0; i < n; i++){
        if(soLuongSoNguyenTo1Dong[i] == soLuongSoNguyenToMax){
            printf("Dòng %d: ", i);
            for(int j = 0; j < m; j++){
                printf("%5d", arr[i * m + j]);
            }
            printf("\n");
        }
    }

    free(soLuongSoNguyenTo1Dong);
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

    timDongNhieuSoNguyenToNhat(arr, n, m);

    free(arr);
    return 0;
}


