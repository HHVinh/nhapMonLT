// Bài 312 + 314: Viết hàm nhập xuất ma trận số thực

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
        if((i + 1) % m == 0){
            printf("\n");
        }
    }
}

int main(){

    int n,m;
    printf("Nhập n - m  của ma trận: ");
    scanf("%d%d", &n, &m);

    float *arr = (float*) malloc(n * m * sizeof(float));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n ,m);
    xuat(arr, n, m);

    free(arr);
    return 0;

}