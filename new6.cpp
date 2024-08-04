#include <stdio.h>

int main()
{
   int a, b;
   printf("Nhập số nguyên a: ");
   scanf("%d", &a);
   printf("Nhập số nguyên b: ");
   scanf("%d", &b);

   int s;
   s = a + b;
   printf("Tổng của %d + %d = %d\n", a, b, s);

   return 0;
}
