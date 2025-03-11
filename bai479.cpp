#include <stdio.h>
#include <stdlib.h>

// Khai báo kiểu dữ liệu đơn thức P(x) = ax^n
struct DonThuc {
    float heSo;  // Hệ số a
    int soMu;    // Số mũ n
};

typedef struct DonThuc dt;

// Hàm nhập đơn thức
void nhapDonThuc(dt *p) {
    printf("Nhập hệ số a: ");
    scanf("%f", &p->heSo);
    
    printf("Nhập số mũ n: ");
    scanf("%d", &p->soMu);
}

// Hàm xuất đơn thức
void xuatDonThuc(dt p) {
    if (p.soMu == 0) {
        printf("P(x) = %.2f\n", p.heSo);  // Nếu số mũ là 0, chỉ in hệ số
    } else if (p.soMu == 1) {
        printf("P(x) = %.2fx\n", p.heSo);  // Nếu số mũ là 1, chỉ in ax
    } else {
        printf("P(x) = %.2fx^%d\n", p.heSo, p.soMu);  // In đầy đủ ax^n
    }
}

// Hàm main để chạy chương trình
int main() {
    dt p;
    nhapDonThuc(&p);
    xuatDonThuc(p);
    return 0;
}
