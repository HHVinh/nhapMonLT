#include <stdio.h>

int main() {
   int n, ketqua = 0;
   printf("Hay nhap so bat ki: ");
   scanf("%d",&n);
   for(int i = 1; i<= n/2; i++){
        if( n % i == 0){
            ketqua += 1;
            printf("Ket qua khi i = %d la: %d\n", i, ketqua);
        }
    }
    ketqua += 1;
    printf("Ket qua la: %d\n", ketqua);
    return 0;
}