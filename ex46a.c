#include <stdio.h>

int main() {
    int n, dem = 0;
    printf("Nhập số nguyên dương n: ");
    scanf("%d", &n);

    // Duyệt từng chữ số và đếm chữ số lẻ
    while (n > 0) {
        dem += (n % 10) % 2;  // Thêm 1 nếu chữ số cuối là số lẻ vì số lẻ %2 = 1, còn chẵn %2 = 0
        n /= 10;              // Bỏ chữ số cuối
    }

    printf("Số lượng chữ số lẻ là: %d\n", dem);
    return 0;
}
