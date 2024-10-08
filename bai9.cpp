#include <stdio.h>
#include <math.h>
// int: %d
// long long: %lld
// float: %f
// double: %lf
// char: %c

int main() 
{
    int n;
    long long s = 1;
    printf("Nhập số n: ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        s = s*i;
    }
    printf("Kết quả là: %lld", s);
    return 0;
}