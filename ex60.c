#include <stdio.h>

int main() {
     int n, soCuoi, soHienTai, dem = 1;
     printf("Hãy nhập số bất kì: ");
     scanf("%d",&n);
     int nBanDau = n;
     soCuoi = n%10;
     n/=10;
     while (n>0)
     {    
          soHienTai = n%10;
          if (soHienTai >= soCuoi){
               dem = 0;
               break;
          }
          soCuoi = soHienTai;
          n /= 10;         
     }
     if (dem)
     {
          printf("%d là số tăng dần!\n",nBanDau);
     } else{
          printf("%d không là số tăng dần!\n",nBanDau);
     }
     return 0;
}
