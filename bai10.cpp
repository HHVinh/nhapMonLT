#include <stdio.h>
#include <math.h>
// int: %d
// long long: %lld
// float: %f
// double: %lf
// char: %c

int main() 
{
    int x,n;
    long long T = 1.0;
    printf("Nhập số x: ");
    scanf("%d",&x);
    printf("Nhập số n: ");
    scanf("%d",&n);
    for(int i = 1; i <=n; i++)
    {
        T = (x*T);
    }
    printf("Kết quả là: %lld", T);
    return 0;
}