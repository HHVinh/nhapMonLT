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
    printf("Nhập số n:");
    scanf("%d", &n);
    int s = 0;
    for (int i = 1; i <= n; i ++)
    {
        s = s +i;
    }

    printf("Kết quả là: %d",s);
    return 0;
}