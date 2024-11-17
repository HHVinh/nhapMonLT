#include <stdio.h>

int main() {
   int n, ketQua = 0;
   printf("Hãy nhập số bất kì: ");
   scanf("%d",&n);
   int nBanDau = n;
   while (n>0)
   {
        ketQua = ketQua*10 + n%10;
        n/=10;
   }
     if (ketQua == nBanDau)
     {
          printf("%d là số hoàn thiện!\n",nBanDau);
     } else{
          printf("%d không là số hoàn thiện!\n",nBanDau);
     }
     return 0;
}
