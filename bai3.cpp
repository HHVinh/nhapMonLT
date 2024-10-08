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
    float s = 0;
    printf("Nhập số n: ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        s = s + 1.0/i;
    }
    printf("Kết quả là: %f", s);
    return 0;
}