#include <stdio.h>
#include <math.h>
// int: %d
// long long: %lld
// float: %f
// double: %lf
// char: %c

int main() 
{
    int a, b;
    printf("Nhập số a:");
    scanf("%d", &a);
    printf("Nhập số b:");
    scanf("%d", &b);

    int s;
    s = a + b;
    printf("Tổng số nguyên %d + %d = %d", a, b, s);
    return 0;
}