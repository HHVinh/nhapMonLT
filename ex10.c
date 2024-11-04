#include <stdio.h>

int main(){
    int n, tich = 1;
    printf("Hay nhap so bat ki: ");
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        tich *= i;
        printf("Ket qua i = %d la %d\n",i,tich);
    }
    printf("Ket qua la: %d", tich);
    return 0;
}