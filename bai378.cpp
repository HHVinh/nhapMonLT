// Bài 378: Tìm 1 chữ số xuất hiện nhiều nhất
#include <stdio.h>
#include <stdlib.h>

void nhap(int *a, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("Nhập A[%d][%d]: ", i/m, i%m);
        scanf("%d", &a[i]);
    }
}

void xuat(int *a, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("%5d", a[i]);
        if((i+1) % m == 0) printf("\n");
    }
}

void timChuSoXuatHienNhieuNhat(int *a, int n, int m){
    int dem[10] = {0}; // đếm tần suất 0 → 9

    for(int i = 0; i < n * m; i++){
        int x = abs(a[i]); // bỏ dấu âm
        if(x == 0) dem[0]++; // trường hợp đặc biệt
        while(x > 0){
            int cs = x % 10;
            dem[cs]++;
            x /= 10;
        }
    }

    // Tìm số lần xuất hiện lớn nhất
    int max = dem[0];
    for(int i = 1; i < 10; i++){
        if(dem[i] > max)
            max = dem[i];
    }

    // In ra tất cả chữ số có số lần xuất hiện = max
    printf("\nCác chữ số xuất hiện nhiều nhất (%d lần): ", max);
    for(int i = 0; i < 10; i++){
        if(dem[i] == max)
            printf("%d ", i);
    }
    printf("\n");
}

int main(){
    int n, m;
    printf("Nhập số dòng và cột: ");
    scanf("%d%d", &n, &m);

    int *a = (int*) malloc(n * m * sizeof(int));
    if(a == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    nhap(a, n, m);
    printf("\nMa trận vừa nhập:\n");
    xuat(a, n, m);

    timChuSoXuatHienNhieuNhat(a, n, m);

    free(a);
    return 0;
}
