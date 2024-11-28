#include <stdio.h>
#include <math.h>

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

int KiemTraSoNT(int b){
    if(b < 2){
        return 0;
    } else{
        for(int i = 2; i <= sqrt(b); i++){
            if(b % i == 0){
                return 0;
            }
        }
        return 1;
    }
}

float TrungBinhSoTN(int m, int n, int a[100][100]){
    int Dem = 0; int Tong = 0; float TrungBinh = 0;
    for(int i = 0; i < m; i ++){
        for(int j = 0; j < n; j++){
            if(KiemTraSoNT(a[i][j])){
                Dem +=1; Tong += a[i][j];
            }
        }
    }
    if(Dem == 0){
        printf("Không có số nguyên tố trong ma trận");
        return 0;
    } else{
        return (float) Tong/Dem;
    }
}


int main(){

    int m, n; int a[100][100];
    printf("Hãy nhập số hàng và cột của ma trận MxN: ");
    scanf("%d %d",&m, &n);

    NhapMT(m,n,a);
    printf("Ma trận là: \n");
    XuatMT(m,n,a);
    
    float KetQua = TrungBinhSoTN(m,n,a);
    if(KetQua != 0){
        printf("Kết quả là: %f\n", KetQua);
    }
    return 0;
}