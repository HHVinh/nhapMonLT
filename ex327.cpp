#include <stdio.h>

void Nhap(int m, int n, int a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhập giá trị của hàng %d - cột %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void Xuat(int m, int n, int a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int TinhTongBien(int m, int n, int a[100][100]){
    int Tong = 0;
    for(int j = 0; j<n; j++){
        Tong += a[0][j];
        Tong += a[m-1][j];
    }

    for(int i = 1; i<m-1; i++){
        Tong += a[i][0];
        Tong += a[i][n-1];
    }
    return Tong;
}

int main(){
    int m, n; int a[100][100];
    printf("Nhập số hàng và cột của mảng hai chiều MxN: ");
    scanf("%d %d",&m,&n);

    Nhap(m,n,a);
    printf("Mảng vừa nhập là:\n");
    Xuat(m,n,a);
    printf("\n Kết quả là: \n");
    int KetQua = TinhTongBien(m,n,a);
    printf("Tổng trên biên là: %d\n", KetQua);

    return 0;
}