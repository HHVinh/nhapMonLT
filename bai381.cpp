// Bài 381: Tìm giá trị xuất hiện nhiều nhất
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập A[%d][%d]: ", i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0) printf("\n");
    }
}

void timGiaTriXuatHienNhieuNhat(int *arr, int n, int m) {
    int size = n * m;
    int *temp = (int*) malloc((size + 1) * sizeof(int));

    for(int i = 0; i < size; i++)
        temp[i] = arr[i];
    temp[size] = INT_MIN; // lính canh

    int maxCount = 0;

    // Mảng kết quả tạm lưu
    int ketQua[100]; // size tối đa 100 phần tử
    int soLuong = 0;

    for(int i = 0; i < size; i++) {
        if(temp[i] == INT_MIN) continue;

        int count = 1;
        for(int j = i + 1; j < size; j++) {
            if(temp[j] == temp[i]) {
                count++;
                temp[j] = INT_MIN;
            }
        }

        if(count > maxCount) {
            maxCount = count;
            soLuong = 0; // reset lại danh sách
            ketQua[soLuong++] = temp[i];
        } else if(count == maxCount) {
            ketQua[soLuong++] = temp[i];
        }
    }

    // In kết quả
    printf("\nGiá trị xuất hiện nhiều nhất (%d lần): ", maxCount);
    for(int i = 0; i < soLuong; i++) {
        printf("%d ", ketQua[i]);
    }
    printf("\n");

    free(temp);
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
    
    timGiaTriXuatHienNhieuNhat(arr, n, m);

    free(arr);
    return 0;
}
