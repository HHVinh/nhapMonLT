#include <stdio.h>

int pt1(int a, int b){
     printf("Hãy nhập 2 hệ số a và b của phương trình  ax + b = 0: ");
     scanf("%d %d", &a, &b);
     if(a == 0){
          if (b == 0)
          {
               printf("Ptr vô số nghiệm\n");
          }else{
               printf("Ptr vô nghiệm\n");
          } 
     }
     else{
          double x = (1.0*-b)/a;
          printf("Ptr có nghiệm x = %f\n", x);
     }
     return 0;
}


int main() {
    int n, a, b, c, d, e;
    printf("1 - Giải phương trình bậc 1\n");
    printf("2 - Giải phương trình bậc 2\n");
    printf("4 - Giải phương trình bậc 4\n");
    printf("Hãy nhập lựa chọn của bạn:\n");
    scanf("%d",&n);

    if(n == 1){
     pt1(a,b);
    }else{
    printf("Dữ liệu bạn nhập không hợp lệ!\n");
    }
    return 0;
}

