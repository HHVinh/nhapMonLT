#include <iostream>

int main() 
{
    int a;
    printf("Nhập một số nguyên bất kì: ");
    scanf("%d",&a);
    int i = 1;
    while (i <= a)
    {
        printf("%5d",i);
        i ++;
    }   
    return 0;
}
