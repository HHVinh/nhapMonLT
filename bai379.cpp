// Bài 379: Đếm số lượng min
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

int soMin(int *arr, int n, int m){
    int min = INT_MAX;
    for(int i = 0; i < n*m; i++){
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
}
int demSoLuongMin(int *arr, int n, int m){
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
    temp[size] = INT_MAX;

    int min = soMin(arr,n,m);
    int dem = 0;
    int i = 0;

    while(temp[i] != INT_MAX){
        if(temp[i] == min){
            dem++;
        }
        i++;
    }

    free(temp);

    return dem;
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

    int min = soMin(arr, n, m);
    int demMin = demSoLuongMin(arr,n,m);
    printf("\nSố nhỏ nhất trong ma trận là: %d\nCó số lượng là: %d", min, demMin);

    free(arr);
    return 0;

}
