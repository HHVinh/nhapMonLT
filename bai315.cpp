// Bài 315: Viết hàm tìm giá trị lớn nhất trong ma trận số thực
#include <stdio.h>
#include <stdlib.h>

void nhap(float *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%f", &arr[i]);
    }
}

void xuat(float *arr, int n, int m){
    printf("\nMa trận là: \n");
    for(int i = 0; i < n*m; i++){
        printf("%8.2f", arr[i]);
        if((i+1) % m == 0){
            printf("\n");
        }
    }
}

float phanTuMax(float *arr, int n, int m){
    float maxValue = arr[0];
    for(int i = 1; i < n*m; i++){
        if(arr[i] > maxValue){
            maxValue = arr[i];
        }
    }
    return maxValue;
}

int main(){

    int n, m;
    printf("Nhập n dòng và m cột: "); scanf("%d%d", &n, &m);

    float *arr = (float*) malloc(n * m * sizeof(float));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }
    
    nhap(arr, n, m);
    xuat(arr, n, m);

    float maxValue = phanTuMax(arr, n, m);
    printf("Phần tử lớn nhất ma trận vừa nhập là: %8.2f", maxValue);

    free(arr);
    return 0;

}