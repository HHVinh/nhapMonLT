// Bài 390(*): Liệt kê các cột nhiều chữ số nhất trong ma trận các số nguyên
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

int diemChuSo(int a) {
    if (a == 0) return 1;
    a = abs(a);  // Lấy trị tuyệt đối để tính đúng số chữ số
    int dem = 0;
    while (a > 0) {
        dem++;
        a /= 10;
    }
    return dem;
}

void timCotCoNhieuChuSoNhat(int *arr, int n, int m){
    int *tongChuSoTrenCot = (int*) calloc(m, sizeof(int));
    if(tongChuSoTrenCot == NULL){
        printf("Lỗi cấp phát.\n");
        exit(1);
    }

    int tongChuSoMax = INT_MIN;

    // Tính tổng chữ số trên cột
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            tongChuSoTrenCot[i] += diemChuSo(arr[j * m + i]);
        }
        if(tongChuSoTrenCot[i] > tongChuSoMax)
            tongChuSoMax = tongChuSoTrenCot[i];
    }

    // Thông báo cột nào có tổng chữ số lớn nhất
    printf("\nCác cột có tổng chữ số lớn nhất là: ");
    for(int i = 0; i < m; i++){
        if(tongChuSoTrenCot[i] == tongChuSoMax){
            printf("%d ", i);
        }
    }
    printf("\n");

    // In ra nội dung các cột theo kiểu ma trận
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tongChuSoTrenCot[j] == tongChuSoMax){
                printf("%5d", arr[i * m + j]);
            }
        }
        printf("\n");
    }

    free(tongChuSoTrenCot);
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

    timCotCoNhieuChuSoNhat(arr,n,m);

    free(arr);
    return 0;

}

