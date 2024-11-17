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
          ketQua = soMin;
     } else{
          for (int i = 1; i < soMin/2; i++)
          {
               if (soMin % i == 0 && soMax % i == 0)
               {
                    ketQua = i;
               }
          }
     }  
     printf("Ước chung lớn nhất của %d và %d là: %d", a,b, ketQua);
     return 0;
}
