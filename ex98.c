#include <stdio.h>

void giaiHePhuongTrinh(float a, float b, float c, float d, float e, float f) {
    // Tính định thức D
    float D = a * e - b * d;
    
    // Kiểm tra D có khác 0 không
    if (D == 0) {
        // Nếu D = 0, kiểm tra xem hệ có vô nghiệm hoặc vô số nghiệm
        if (a * f == c * d && b * f == c * e) {
            printf("Hệ phương trình có vô số nghiệm.\n");
        } else {
            printf("Hệ phương trình vô nghiệm.\n");
        }
    } else {
        // Nếu D khác 0, tính x và y
        float x = (c * e - b * f) / D;
        float y = (a * f - c * d) / D;
        
        printf("Nghiệm của hệ phương trình là: x = %.2f, y = %.2f\n", x, y);
    }
}

int main() {
    float a, b, c, d, e, f;
    
    // Nhập các hệ số từ bàn phím
    printf("Nhập các hệ số a, b, c, d, e, f cho hệ phương trình:\n");
    printf("ax + by = c\n");
    printf("dx + ey = f\n");
    printf("Nhập a: ");
    scanf("%f", &a);
    printf("Nhập b: ");
    scanf("%f", &b);
    printf("Nhập c: ");
    scanf("%f", &c);
    printf("Nhập d: ");
    scanf("%f", &d);
    printf("Nhập e: ");
    scanf("%f", &e);
    printf("Nhập f: ");
    scanf("%f", &f);

    // Gọi hàm giải phương trình
    giaiHePhuongTrinh(a, b, c, d, e, f);

    return 0;
}
