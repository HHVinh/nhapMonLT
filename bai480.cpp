#include <stdio.h>

struct DaThuc {
    int bac;         // Bậc của đa thức
    float heSo[100]; // Mảng lưu hệ số của các bậc (giới hạn tối đa là 100)
};
typedef struct DaThuc dt;

// Hàm nhập đa thức
void nhapDaThuc(dt *p) {
    printf("Nhập bậc của đa thức: ");
    scanf("%d", &p->bac);

    for (int i = p->bac; i >= 0; i--) {
        printf("Nhập hệ số a[%d]: ", i);
        scanf("%f", &p->heSo[i]);
    }
}

// Hàm xuất đa thức
void xuatDaThuc(dt p) {
    printf("P(x) = ");
    for (int i = p.bac; i >= 0; i--) {
        if (p.heSo[i] != 0) { // Bỏ qua hệ số bằng 0
            if (i == p.bac) {
                printf("%.2fx^%d", p.heSo[i], i);
            } else {
                if (p.heSo[i] > 0) {
                    printf(" + %.2fx^%d", p.heSo[i], i);
                } else {
                    printf(" - %.2fx^%d", -p.heSo[i], i);
                }
            }
        }
    }
    printf("\n");
}

// Hàm main để chạy chương trình
int main() {
    dt p;
    nhapDaThuc(&p);
    xuatDaThuc(p);
    return 0;
}
