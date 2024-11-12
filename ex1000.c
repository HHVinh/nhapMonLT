#include <stdio.h>
#include <math.h>

double tinhSn(int n){
    double ketQua = 0;
    for(int i = 1; i<=n; i++){
        ketQua = sqrt(2+ketQua);
    }
    return ketQua;
}

int main(){
    int n;
    double canBac = sqrt(2);
    printf("Nhập một số bất kì: ");
    scanf("%d",&n);

    double ketQua = tinhSn(n);
    printf("S(%d) = %.10f\n", n, ketQua);
    
    return 0;
}