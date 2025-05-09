// Bài 377: Tìm số nguyên tố lớn nhất
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

int soNguyenTo(int a){
    if(a < 2) return 0;  // Không phải số nguyên tố

    for(int i = 2; i * i <= a; i++){
        if(a % i == 0){
            return 0;    // Không phải số nguyên tố
        }
    }
    return 1;  // Là số nguyên tố
}

int timSoNguyenToLonNhat(int *arr, int n, int m){
    int maxNguyenTo = -1;
    for(int i = 0; i < n*m; i++){
        if(soNguyenTo(arr[i]) && arr[i] > maxNguyenTo){
            maxNguyenTo = arr[i];
        }
    }
    return maxNguyenTo;
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

    int kq = timSoNguyenToLonNhat(arr, n, m);
    if(kq != -1)
        printf("\nSố nguyên tố lớn nhất trong ma trận là: %d", kq);
    else
        printf("\nKhông có số nguyên tố nào trong ma trận.");

    free(arr);
    return 0;
}
