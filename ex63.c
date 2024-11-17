#include <stdio.h>
#include <math.h>

int min(int a, int b){
     return(a<=b)? a:b;
}

int max(int a, int b){
     return(a>b)? a:b;
}

int main() {
     int a, b, soMin, soMax, ketQua;
     printf("Hãy nhập hai số bất kì: ");
     scanf("%d %d",&a,&b);
     soMin = min(a,b);
     soMax = max(a,b);
     if (soMax % soMin == 0)
     {
          ketQua = soMax;
     } else{
          for (int i = 1; ; i++)
          {
               if ((soMax *i) % soMin == 0)
               {
                    ketQua = soMax*i;
                    break;
               }
          }
     }  
     printf("Bội chung nhỏ nhất của %d và %d là: %d", a,b, ketQua);
     return 0;
}
