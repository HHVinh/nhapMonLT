#include <stdio.h>

int main(){
    int n;
    double tong = 0;
    printf("Hay nhap so bat ki: ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        tong += (1.0*2*i-1)/(2*i);
        printf("%f\n",tong);
    }
    printf("Ket qua la: %f", tong);
    return 0;
}