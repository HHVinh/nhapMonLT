#include <stdio.h>

int main() {
    int n, tong = 0;
    printf("Nhập một số nguyên dương n: ");
    scanf("%d", &n);

    for (int i = 1; ; i++) { // Không cần điều kiện kết thúc vì có break
        if (tong + i >= n) { // Kiểm tra nếu thêm i vào sẽ vượt quá n
            printf("Giá trị k lớn nhất thỏa mãn S(k) < n là: %d\n", i - 1);
            break;
        }
        tong += i; // Cộng i vào tổng
    }

    return 0;
}
