// Bài 394: Dịch xuống xoay vòng các hàng trong ma trận

#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("%5d", arr[i]);
        if((i + 1) % m == 0){
            printf("\n");
        }
    }
}

void dichXuongHang(int *arr, int n, int m){
    int *temp = (int*) malloc(m * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ"); exit(1);
    }

    for(int i = 0; i < m; i++){
        temp[i] = arr[i];
    }
    
    int j = 0;
    for(int i = m; i < n*m; i++){
        arr[j] = arr[i];
        j++;
    }

    for(int i = 0; i < m; i++){
        arr[j] = temp[i];
        j++;
    }

    free(temp);
}

void dichXuongNhieuHang(int *arr, int n, int m){
    int k; 
    printf("\nNhập số lượng dòng muốn dịch: "); 
    scanf("%d",&k);

    k = k % n;
    if(k == 0) return;
    
    for(int i = 0; i < k; i++){
        dichXuongHang(arr,n,m);
    }
}

int main(){

    int n, m; 
    printf("Nhập số dòng (n) và số cột (m): ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ"); exit(1);
    }

    nhap(arr, n , m);
    printf("\nMa trận vừa nhập là: \n");
    xuat(arr,n,m);

    if(n < 2){
        printf("\nKhông thể dịch hàng ma trận.");
    } else{
        dichXuongNhieuHang(arr, n, m);
        printf("\nMa trận mới là: \n");
        xuat(arr,n,m);
    }

    free(arr);
    return 0;
}