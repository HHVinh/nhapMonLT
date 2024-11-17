#include <stdio.h>
#include <math.h>

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

int pt2(int a, int b, int c){
     printf("Hãy nhập 3 hệ số a, b và c của phương trình  ax^2 + bx + c = 0: ");
     scanf("%d %d %d", &a, &b, &c);
     if (a == 0)
     {
        if(b == 0){
          if (c == 0){
               printf("Ptr vô số nghiệm\n");
          }else{
               printf("Ptr vô nghiệm\n");
          } 
          }
          else{
               double x = (1.0*-c)/b;
               printf("Ptr có nghiệm x = %f\n", x);
          }
     } else{
          int delta = b*b - (4*a*c);
          if (delta < 0){
               printf("Ptr vô nghiệm\n");
          } else if (delta == 0){
               double x = (1.0*-b)/(2*a);
               printf("Ptr có nghiệm kép x = %f\n",x);
          } else{
               double x1 = ((1.0*-b)+ sqrt(delta))/(2*a);
               double x2 = ((1.0*-b)- sqrt(delta))/(2*a);
               printf("Phương trình có 2 nghiệm phân biệt là:\n");
               printf("x1 = %f\nx2 = %f\n", x1, x2);
          }
     }
     return 0;
}

/*int pt4(int a, int b, int c, int d, int e){
    printf("Hãy nhập 5 hệ số a, b, c, d, e của phương trình bậc 4 ax^4 + bx^3 + cx^2 + dx + e = 0: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    int delta = b * b - 4 * a * c;
        if (delta < 0) {
            printf("Phương trình vô nghiệm.\n");
            return 0;
        }
        // Tiến hành giải như đã trình bày ở trên cho phương trình bậc 2
        double x1_1 = (-b + sqrt(delta)) / (2 * a);
        double x1_2 = (-b - sqrt(delta)) / (2 * a);

        printf("Phương trình bậc 4 có 2 nghiệm phân biệt cho phần bậc 2: \n");
        printf("Nghiệm 1: x = %f\n", x1_1);
        printf("Nghiệm 2: x = %f\n", x1_2);    

    return 0;
}*/

int main() {
    int n, a, b, c, d, e;
    printf("1 - Giải phương trình bậc 1\n");
    printf("2 - Giải phương trình bậc 2\n");
    printf("4 - Giải phương trình bậc 4\n");
    printf("Hãy nhập lựa chọn của bạn:\n");
    scanf("%d",&n);

    if(n == 1){
     pt1(a,b);
    } else if (n == 2){
     pt2(a,b,c);
    } else if (n ==4){
     pt4(a,b,c,d,e);
    }else{
    printf("Dữ liệu bạn nhập không hợp lệ!\n");
    }
    return 0;
}

