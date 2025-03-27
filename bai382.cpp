// Bài 382: Tìm số chính phương lớn nhất
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

int soChinhPhuong(int a){
    if(a < 0) return -1; // Không có số chính phương âm
    int i = 0;
    while(i * i <= a){
        if(i * i == a)
            return a;  // Trả về chính nó nếu là số chính phương
        i++;
    }
    return -1; // Không phải số chính phương
}


int timSoChinhPhuongMax(int *arr, int n, int m){
    int size = n * m;

    // Tạo mảng mới có thêm 1 phần tử cho lính canh
    int *temp = (int*) malloc((size + 1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát.\n");
        exit(1);
    }

    // Sao chép dữ liệu
    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }

    // Đặt lính canh
    temp[size] = INT_MIN;

    int soChinhPhuongMax = -1;
    int i = 0;

    while(temp[i] != INT_MIN){
        if(soChinhPhuong(temp[i]) && temp[i] > soChinhPhuongMax){
            soChinhPhuongMax = temp[i];
        }
        i++;
    }

    free(temp);

    return soChinhPhuongMax;
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

    int ketQua = timSoChinhPhuongMax(arr, n, m);

    if(ketQua == -1){
        printf("\nKhông có số chính phương nào trong ma trận.");
    } else {
        printf("\nSố chính phương lớn nhất trong ma trận là: %d",ketQua);
    }

    free(arr);
    return 0;

}
