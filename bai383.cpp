// Bài 383: Tìm số hoàn thiện nhỏ nhất
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

int soHoanThien(int a){
    if(a <= 0) return 0;
    int tong = 0;
    for(int i = 1; i <= a/2; i++)
        if(a % i == 0)
            tong += i;
    return tong == a; // Hàm này trả về 1 nếu đúng, 0 nếu không phải.
}

int timSoHoanThienNhoNhat(int *arr, int n, int m){
    int size = n * m;
    int *temp = (int*) malloc((size + 1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát.\n");
        exit(1);
    }

    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }

    // Lính canh
    temp[size] = INT_MIN;

    int soHoanThienMin = INT_MAX;
    int i = 0;
    int timThay = 0;  // Biến cờ

    while(temp[i] != INT_MIN){
        if(soHoanThien(temp[i]) && temp[i] < soHoanThienMin){
            soHoanThienMin = temp[i];
            timThay = 1;
        }
        i++;
    }

    free(temp);

    if(timThay)
        return soHoanThienMin;
    else
        return -1;
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

    int ketQua = timSoHoanThienNhoNhat(arr, n, m);

    if(ketQua == -1){
        printf("\nKhông có số hoàn thiện nào trong ma trận.");
    } else {
        printf("\nSố hoàn thiện nhỏ nhất trong ma trận là: %d",ketQua);
    }

    free(arr);
    return 0;

}
