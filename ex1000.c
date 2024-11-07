#include <stdio.h>
#include <math.h>

int main() {
    int n, ketqua = 0;
    printf("Hãy nhập số bất kỳ: ");
    scanf("%d", &n);
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            ketqua += i;
        }
    }
    printf("Tong cac uoc = %d\n",ketqua);
    if (ketqua == n)
    {
        printf("%d la so hoan thien \n",n);
    }
    else{
        printf("%d khong la so hoan thien \n",n);
    }
    return 0;
}
