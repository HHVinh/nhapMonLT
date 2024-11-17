#include <stdio.h>

// Hàm tính Ước chung lớn nhất (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Hàm tính Bội chung nhỏ nhất (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b); // Sử dụng công thức LCM
}

int main() {
    int a, b, ketQua;
    printf("Hãy nhập hai số bất kì: ");
    scanf("%d %d", &a, &b);
    
    ketQua = lcm(a, b); // Tính LCM
    printf("Bội chung nhỏ nhất của %d và %d là: %d\n", a, b, ketQua);
    return 0;
}
