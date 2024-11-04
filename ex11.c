#include <stdio.h>

int main(){
    int n, luyThua = 1, ketQua = 0;
    printf("Hay nhap so bat ki: ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        luyThua *= i;
        ketQua += luyThua;
        printf("Ket qua i = %d la %d\n",i,ketQua);
    }
    printf("Ket qua la: %d", ketQua);
    return 0;
}