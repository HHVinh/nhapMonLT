#include <stdio.h>
#include <math.h>

// Hàm tìm giá trị lớn hơn giữa hai số
int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main() {
    int n, ketqua = 0;
    printf("Hãy nhập số bất kỳ: ");
    scanf("%d", &n);

    // Kiểm tra nếu n là số lẻ
    if (n % 2 == 1) {
        printf("Kết quả là: %d\n", n);
    } else {
        // Tìm ước số lẻ lớn nhất của n
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0 && i % 2 == 1) {  // Kiểm tra i là ước số lẻ của n
                ketqua = max(ketqua, i);  // Cập nhật ước số lẻ lớn nhất
            }
        }
        printf("Kết quả là: %d\n", ketqua);  // In kết quả
    }
    
    return 0;
}
