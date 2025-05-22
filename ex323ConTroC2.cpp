// Bài 323: Tính tích các giá trị dương trên 1 cột trong ma trận các số thực
#include <stdio.h>
#include <stdlib.h>

void nhapMang(float** arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Nhập phần tử A[%d][%d]: ", i, j);
            scanf("%f", &arr[i][j]);
        }
    }
}

void xuatMang(float** arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%8.2f", arr[i][j]);
        }
        printf("\n");
    }
}

void tongSoDuongTungCot(float** arr, int n, int m){
    for(int j = 0; j < m; j++){
        float tong = 1;
        int coSoDuong = 0;
        for(int i = 0; i < n; i++){
            if(arr[i][j] > 0){
                tong *= arr[i][j];
                coSoDuong = 1;
            }
        }
        if(coSoDuong){
            printf("Tổng cột %d là: %.2f\n", j + 1, tong);
        } else{
            printf("Tổng cột %d là: 0\n", j + 1);
        }
    }
}

int main(){

    int n, m;
    printf("Nhập số lượng dòng, cột: ");
    scanf("%d%d", &n,&m);
    

    float** arr = (float**) malloc(n * sizeof(float*));
    if(arr == NULL){
        printf("Lỗi!");
        return 1;
    }

    for(int i = 0; i < n; i++){
        arr[i] = (float*) malloc(m * sizeof(float));
        if(arr[i] == NULL){
        printf("Lỗi!");
        for(int j = 0; j < n; j++){
            free(arr[j]);
        }
        free(arr);
        return 1;
        }
    }

    nhapMang(arr, n, m);
    printf("Ma trận vừa nhập là: \n");
    xuatMang(arr, n, m);

    tongSoDuongTungCot(arr, n, m);

    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);

    return 0;
}