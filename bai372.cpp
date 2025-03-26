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

int timMaxTrenDong(int *dong, int m){
    // Tạo bản sao dòng + lính canh
    int *temp = (int*) malloc((m + 1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    for(int i = 0; i < m; i++){
        temp[i] = dong[i];
    }
    temp[m] = INT_MIN;  // lính canh

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

void timMaxTungDong(int *arr, int n, int m){
    for(int i = 0; i < n; i++){
        int *dong = arr + i * m; // Có thể thay bằng &arr[i * m]
        int max = timMaxTrenDong(dong, m);
        printf("Giá trị lớn nhất của dòng %d là: %d\n", i, max);
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

    timMaxTungDong(arr, n, m);

    free(arr);
    return 0;
}
