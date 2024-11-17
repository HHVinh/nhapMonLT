#include <stdio.h>

int main() {
   int n, dem = 0;
   printf("Hãy nhập số bất kì: ");
   scanf("%d",&n);
   int nBanDau = n;
   while (n>0)
   {
        if((n%10) %2 == 0){
        dem += 1;
        break;
        }
        n/=10;
   }
   if (dem >= 1)
   {
    printf("%d có chữ số chẵn!",nBanDau);
   } else{
    printf("%d toàn chữ số lẻ!",nBanDau);
   }   
    return 0;
}
