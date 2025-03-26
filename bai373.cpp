// Bài 373: Tìm giá trị nhỏ nhất trên 1 cột
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

int timMinTrenCot(int *cot, int n){
    // Tạo bản sao dòng + lính canh
    int *temp = (int*) malloc((n + 1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        temp[i] = cot[i];
    }

    temp[n] = INT_MAX;

    int min = temp[0];
    int i = 1;
    while(temp[i] != INT_MAX){
        if(temp[i] < min){
            min = temp[i];
        }
        i++;
    }

    free(temp);
    return min;
}

void timMinTungCot(int *arr, int n, int m){
    for(int i = 0; i < m; i++){ // Duyệt từng cột
        // Tạo mảng chứa các phần tử của cột i
        int *cot = (int*) malloc(n * sizeof(int));
        if(cot == NULL){
            printf("Lỗi cấp phát bộ nhớ.\n");
            exit(1);
        }

        for(int j = 0; j < n; j++){
            cot[j] = arr[j * m + i]; // Lấy phần tử ở cột i, dòng j
        }

        int min = timMinTrenCot(cot, n);
        printf("Giá trị nhỏ nhất của cột %d là: %d\n", i, min);
        free(cot);
    }
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

    timMinTungCot(arr, n, m);

    free(arr);
    return 0;
}
