#include <stdio.h>

void NhapMT(int m, int n, float a[100][100]){
    for(int i = 0; i<m; i++){
        for(int j =0;j<n; j++){
            printf("Nhập giá trị cho dòng %d - cột %d: ", i+1,j+1);
            scanf("%f",&a[i][j]);
        }
    }
}

void XuatMT(int m, int n, float a[100][100]){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("%f ", a[i][j]);
        }
        printf("\n");
    }
}


int main(){

    int m, n; float a[100][100];
    printf("Hãy nhập số hàng và cột của ma trận MxN: ");
    scanf("%d %d",&m, &n);

    NhapMT(m,n,a);
    printf("Ma trận là: \n");
    XuatMT(m,n,a);

    return 0;
}