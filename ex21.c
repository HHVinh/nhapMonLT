#include <stdio.h>

int main() {
   int n, tong = 0;
   printf("Hay nhap so bat ki: ");
   scanf("%d",&n);
   for(int i = 1; i<= n/2; i++){
        if( n % i == 0){
            tong +=i;
            printf("Ket qua khi i = %d la: %d\n", i, tong);
        }
    }
    tong += n;
    printf("Ket qua la: %d\n", tong);
    return 0;
}
