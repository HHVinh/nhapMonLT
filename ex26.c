#include <stdio.h>

int main() {
    int n, ketqua = 1;
    printf("Hãy nhập số bất kỳ: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0 && i % 2 == 1) {
            ketqua *= i;
            printf("Kết quả khi i = %d là: %d\n", i, ketqua);
        }
    }
    if (n % 2 == 1) {
        ketqua *= n;
    }
    printf("Kết quả là: %d\n", ketqua);
    return 0;
}
