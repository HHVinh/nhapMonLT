#include <stdio.h>

typedef struct {
    float x; float y;
} Diem;

void NhapDiem(Diem *d) {
    printf("Nhập tọa độ x: "); 
    scanf("%f", &d->x);

    printf("Nhập tọa độ y: "); 
    scanf("%f", &d->y);
}

void XuatDiem(Diem *d){
    printf("Tọa độ (x, y) trong mặt phẳng Oxy là: (%.2f, %.2f)\n",d->x,d->y);
}

int main() {
    Diem d;
    NhapDiem(&d);
    XuatDiem(&d);
    return 0;
}