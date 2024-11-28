#include <stdio.h>

void NhapMT(int m, int n, int a[100][100]){
    for(int i = 0; i<m; i++){
        for(int j =0;j<n; j++){
            printf("Nhập giá trị cho dòng %d - cột %d: ", i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
}

void XuatMT(int m, int n, int a[100][100]){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

int KiemTra(int m, int n, int a[100][100]){
    int Dem = 0;
    for(int i = 0; i <m; i++){
        for(int j = 0; j<n; j++){
            if(a[i][j] > 2015){
                Dem += 1;
                break;
            }
        }
    }
    if( Dem > 0){
        return true;
    }
    return false;
}

int main(){

    int m, n; int a[100][100];
    printf("Hãy nhập số hàng và cột của ma trận MxN: ");
    scanf("%d %d",&m, &n);

    NhapMT(m,n,a);
    printf("Ma trận là: \n");
    XuatMT(m,n,a);
    
    if(KiemTra(m,n,a)){
        printf("Có số nguyên lớn hơn 2015");
    }
    else{
        printf("Không có số nguyên lớn hơn 2015");
    }
    return 0;
}