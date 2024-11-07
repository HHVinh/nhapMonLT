#include <stdio.h>

int main() {
    int n, dem = 0, ketqua = 0;
    printf("Hãy nhập số bất kỳ: ");
    scanf("%d", &n);
    for(int i = 1; i<=n/2; i++){
        if(n % i == 0 && n % 2 == 1){
            dem += 1;
            ketqua += i;
            printf("Ket qua khi i = %d la: dem = %d, tong = %d\n", i, dem, ketqua);
        }
    }
    if (n % 2 ==0)
    {
        dem += 1;
        ketqua += n;
    }
    printf("Ket qua la: dem = %d, tong = %d\n", dem, ketqua);
    return 0;
}
