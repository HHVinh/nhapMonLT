#include <iostream>

int main() 
{
    int a;
    printf("Nhập một số nguyên bất kì: ");
    scanf("%d", &a);

    int i = 1;
    int s = 0;

    while (i <= a)
    {
        s = s + i;
        i++;
    }   

    printf("Tổng các số từ 1 đến %d là: %d\n", a, s);
    return 0;
}
