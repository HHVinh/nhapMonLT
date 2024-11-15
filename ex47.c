#include <stdio.h>

int main() {
    int n, tong = 0;
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    while (n > 0) {
        if((n%10)%2 ==0){
            tong += (n % 10);
        }
        n /= 10;              // Bỏ chữ số cuối
    }

    printf("Kết quả là: %d\n", tong);
    return 0;
}