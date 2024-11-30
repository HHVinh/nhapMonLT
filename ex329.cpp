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

void MaTranABS(int m, int n, float a[100][100]){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j] < 0){
                a[i][j] *= -1.0;
            }
        }
    }
}

int main(){
    int m, n; float a[100][100];
    printf("Nhập số hàng và cột của mảng hai chiều MxN: ");
    scanf("%d %d",&m,&n);

    Nhap(m,n,a);
    printf("Mảng vừa nhập là:\n");
    Xuat(m,n,a);
    printf("\n Kết quả là: \n");
    MaTranABS(m,n,a);
    Xuat(m,n,a);

    return 0;
}