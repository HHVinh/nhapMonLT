#include <stdio.h>
#include <math.h>

// Hàm kiểm tra số nguyên tố
int isPrime(int n) {
    if (n <= 1) {
        return 0;  // Số nhỏ hơn hoặc bằng 1 không phải là số nguyên tố
    }
    
    // Kiểm tra từ 2 đến căn bậc 2 của n
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return 0;  // Nếu chia hết cho i thì n không phải là số nguyên tố
        }
    }
    return 1;  // Nếu không chia hết cho bất kỳ số nào, n là số nguyên tố
}

int main() {
    int N;
    printf("Nhap vao so nguyen duong N: ");
    scanf("%d", &N);
    
    int sum = 0;  // Biến lưu tổng các số nguyên tố
    
    // Tính tổng các số nguyên tố nhỏ hơn N
    for (int i = 2; i < N; i++) {
        if (isPrime(i)) {
          printf("Các số nguyên tố là %d \n", i);
          sum += i;  // Nếu i là số nguyên tố, cộng vào tổng
        }
    }
    
    printf("Tong cac so nguyen to nho hon %d la: %d\n", N, sum);
    
    return 0;
}
