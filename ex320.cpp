#include <stdio.h>

void Nhap(int m, int n, float a[100][100]){
    for(int i = 0; i <m; i++){
        for(int j = 0; j<n; j++){
            printf("Nhập giá trị của hàng %d - cột %d: ", i+1, j+1);
            scanf("%f", &a[i][j]);
        }
    }
}

void Xuat(int m, int n, float a[100][100]){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("%.2f ",a[i][j]);
        }
        printf("\n");
    }
}

int TinhTongSoDuong(int m, int n, float a[100][100]){
    float Tong = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j] > 0){
                Tong += a[i][j];
            }
        }
    }
    return Tong;
}

int main(){
    int m, n; float a[100][100];
    printf("Nhập số hàng và cột của mảng hai chiều MxN: ");
    scanf("%d %d",&m,&n);

    Nhap(m,n,a);
    printf("Mảng vừa nhập là:\n");
    Xuat(m,n,a);
    float Tong = TinhTongSoDuong(m,n,a);
    printf("Tổng các số dương trong mảng là: %.2f", Tong);

}