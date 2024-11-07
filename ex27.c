#include <stdio.h>

int main() {
    int n, ketqua = 0;
    printf("Hãy nhập số bất kỳ: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n / 2; i++) {
        // Kiểm tra nếu i là ước của n và i là số chẵn
        if (n % i == 0 && i % 2 == 0) {
            ketqua +=1 ;
            printf("Kết quả khi i = %d là: %d\n", i, ketqua);
        }
    }
    if (n % 2 == 0) {
        ketqua += 1;
    }

    printf("Kết quả là: %d\n", ketqua);
    return 0;
}
