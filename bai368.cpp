// Bài 368: Tìm giá trị lớn thứ 2 trong ma trận
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

int timMax2(int *arr, int n, int m){
    int size = n*m;
    arr[size] = INT_MIN; // lính canh

    int max1 = INT_MIN, max2 = INT_MIN;
    int i = 0;

    while(arr[i] != INT_MIN){
        if(arr[i] > max1){
            max2 = max1;
            max1 = arr[i];
        }
        else if(arr[i] > max2 && arr[i] != max1){
            max2 = arr[i];
        }
        i++;
    }

    if(max2 == INT_MIN){
        printf("\nKhông có phần tử lớn thứ 2.");
    }
    else{
        printf("\nSố lớn thứ 2 trong ma trận là: %d.", max2);
    }

    return max2;
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

    timMax2(arr, n,m);
    
    

    free(arr);
    return 0;
}

