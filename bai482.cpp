// Bài 482: Hãy khai báo kiểu dữ liệu biểu diễn khái niệm đường thẳng ax + by + c = 0 trong mặt phẳng Oxy
// và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này

#include <stdio.h>

// Khai báo kiểu dữ liệu đường thẳng với hệ số a, b, c
struct duongThang {
    float a, b, c;
};

typedef struct duongThang dt; // Định nghĩa kiểu mới `dt` để dễ sử dụng

// Hàm nhập dữ liệu cho đường thẳng
void nhap(dt *y) {
    printf("\nNhập giá trị hệ số a, b, c cách nhau bởi khoảng trắng: ");
    scanf("%f %f %f", &y->a, &y->b, &y->c);
}

// Hàm xuất phương trình đường thẳng ra màn hình
void xuat(dt y) {
    // Kiểm tra nếu a = 0, b = 0, c = 0 ⇒ phương trình vô nghĩa: 0 = 0
    if (y.a == 0 && y.b == 0 && y.c == 0) {
        printf("\n0 = 0");
        return;
    }
    // Kiểm tra nếu a = 0, b = 0 nhưng c ≠ 0 ⇒ phương trình vô lý: c = 0
    if (y.a == 0 && y.b == 0 && y.c != 0) {
        printf("\nKhông tồn tại đường thẳng %.2f = 0", y.c);
        return;
    }
    
    printf("\nPhương trình đường thẳng là: ");

    int daInGiaTri = 0; // Biến kiểm tra xem đã in hệ số nào chưa

    // Xử lý hệ số `a`
    if (y.a != 0) {
        printf("%.2fx", y.a);
        daInGiaTri = 1;
    }

    // Xử lý hệ số `b`
    if (y.b > 0) {
        if (daInGiaTri) printf(" + "); // Nếu đã in `a`, thì in dấu `+`
        printf("%.2fy", y.b);
        daInGiaTri = 1;
    } else if (y.b < 0) {
        printf(" - %.2fy", -y.b); // Nếu b âm, đổi dấu khi in ra
        daInGiaTri = 1;
    }

    // Xử lý hằng số `c`
    if (y.c > 0) {
        if (daInGiaTri) printf(" + "); // Nếu đã in `a` hoặc `b`, thì in dấu `+`
        printf("%.2f", y.c);
    } else if (y.c < 0) {
        printf(" - %.2f", -y.c); // Nếu c âm, đổi dấu khi in ra
    }
    
    printf(" = 0\n"); // Kết thúc phương trình
}

int main() {
    dt y;  // Khai báo một đường thẳng
    nhap(&y); // Nhập dữ liệu cho đường thẳng
    xuat(y);  // Xuất phương trình đường thẳng

    return 0;
}
