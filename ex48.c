#include <stdio.h>

int main() {
    int n, tich = 1, dem = 0;
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    while (n > 0) {
        if((n%10)%2 ==1){
            tich *= (n % 10);
            dem = 1;
        }
        n /= 10;              // Bỏ chữ số cuối
    }
    if(dem ==0){
        tich = 0;   
    }
    printf("Kết quả là: %d\n", tich);
    return 0;
}