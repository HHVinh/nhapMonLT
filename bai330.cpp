// Bài 330: Hãy biên đổi ma trận số thực bằng cách thay các giá trị bằng giá trị nguyên gần nó nhất
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nhap(float *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%f", &arr[i]);
    }
}

void xuat1(float *arr, int n, int m){
    printf("\nMa trận vừa nhập là:\n");
    for(int i = 0; i < n*m; i++){
        printf("%8.2f", arr[i]);
        if((i+1) % m == 0) printf("\n");
    }
}

void xuat2(float *arr, int n, int m) {
    printf("\nMa trận vừa thay đổi là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%5.0f", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

void doiSoThucThanhSoNguyen(float *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        arr[i] = round(arr[i]);
    }
}

int main(){

    int n, m; printf("\nNhập hàng và cột: "); scanf("%d%d", &n,&m);

    float *arr = (float*) malloc(n*m *sizeof(float));
    if(arr == NULL){
        printf("\nLỗi cấp phát bộ nhớ."); exit(1);
    }

    nhap(arr,n,m);
    xuat1(arr,n,m);
    
    doiSoThucThanhSoNguyen(arr,n,m);
    xuat2(arr,n,m);

    free(arr);
    return 0;
}

