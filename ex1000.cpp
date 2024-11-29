#include <stdio.h>

void Nhap(int m, int n, float a[100][100]){
    for(int i = 0; i <m; i++){
        for(int j = 0; j<n; j++){
            printf("Nhập giá trị của hàng %d - cột %d:", i+1, j+1);
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

void SapXep(int m, int n, float a[100][100]){
    int Dem = 0; float b[10000];
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            a[i][j] = b[Dem];
            Dem += 1;
        }
    }
    for(int i = 0; i< m*n; i++){
        for(int j = 1; j< m*n; j++){
            if(b[i]>b[j]){
                float temp = b[i]; b[i] = b[j]; b[j] = temp;
            }
        }
    }
    printf("Mảng sau khi sắp xếp là: \n");
    int Dem2 = 0;
    for(int i = 0; i< m; i++){
        for(int j = 0; j< n; j++){
            a[i][j] = b[Dem2];
            Dem2 +=1;
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
    SapXep(m,n,a);
    Xuat(m,n,a);

}