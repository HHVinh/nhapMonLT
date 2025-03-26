// Bài 367: Tìm max trong ma trận đặt lính canh)
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
        if((i+1) % m == 0){
            printf("\n");
        }
    }
}

int timMax(int *arr, int n, int m){
    int size = n * m;
    int *temp = (int*) malloc((size + 1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    for(int i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    temp[size] = INT_MIN;

    int max = temp[0];
    int i = 1;
    while(temp[i] != INT_MIN){
        if(temp[i] > max){
            max = temp[i];
        }
        i++;
    }

    free(temp);
    return max;
}


void inDongCoMax(int *arr, int n, int m){
    int *temp = (int*) calloc(n,sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }
    int max = timMax(arr, n, m);

    for(int i = 0; i < n*m; i++){
        if(arr[i] == max){
            temp[i/m] = 1;
            }
        }

    for(int i = 0; i < n; i++){
        if(temp[i] == 1){
            printf("\nDòng %d: ", i);
            for(int j = 0; j < m; j++){
                printf("%5d", arr[i * m + j]);
            }
        }
    }
    free(temp);
}

int main(){

    int n, m;
    printf("Nhập số dòng và cột: "); scanf("%d%d", &n,&m);

    int *arr = (int*) malloc((n*m +1) *sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\n Ma trận vừa nhập là: \n");
    xuat(arr, n, m);

    int ketQua = timMax(arr, n,m);
    
    printf("\nSố lớn nhất trong ma trận là %d.", ketQua);

    printf("\nDòng chứa số lớn nhất là: \n");

    inDongCoMax(arr,n,m);

    free(arr);
    return 0;
}

