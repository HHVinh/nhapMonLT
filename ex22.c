#include <stdio.h>

int main() {
   int n, ketqua = 1;
   printf("Hay nhap so bat ki: ");
   scanf("%d",&n);
   for(int i = 1; i<= n/2; i++){
        if( n % i == 0){
            ketqua *= i;
            printf("Ket qua khi i = %d la: %d\n", i, ketqua);
        }
    }
    ketqua *= n;
    printf("Ket qua la: %d\n", ketqua);
    return 0;
}