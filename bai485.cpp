#include <stdio.h>
#include <math.h>

typedef struct toaDo3DinhTamGiac {
    float x1, y1, x2, y2, x3, y3;
} toaDo;

void nhap(toaDo *a) {
    printf("\nNhập tọa độ A(x1, y1): ");
    scanf("%f %f", &a->x1, &a->y1);
    printf("\nNhập tọa độ B(x2, y2): ");
    scanf("%f %f", &a->x2, &a->y2);
    printf("\nNhập tọa độ C(x3, y3): ");
    scanf("%f %f", &a->x3, &a->y3);
}

// Công thức tính chu vi tam giác:
// Chu vi = AB + BC + AC
float chuVi(toaDo a) {
    float AB = sqrt(pow(a.x2 - a.x1, 2) + pow(a.y2 - a.y1, 2)); // Tính độ dài cạnh AB
    float BC = sqrt(pow(a.x3 - a.x2, 2) + pow(a.y3 - a.y2, 2)); // Tính độ dài cạnh BC
    float AC = sqrt(pow(a.x3 - a.x1, 2) + pow(a.y3 - a.y1, 2)); // Tính độ dài cạnh AC
    return AB + BC + AC;
}

// Công thức tính diện tích tam giác theo tọa độ:
// Diện tích = 1/2 * | x1(y2 - y3) + x2(y3 - y1) + x3(y1 - y2) |
float dienTich(toaDo a) {
    return 0.5 * fabs(a.x1 * (a.y2 - a.y3) + a.x2 * (a.y3 - a.y1) + a.x3 * (a.y1 - a.y2));
}

// Công thức tính tọa độ trọng tâm tam giác:
// G(xG, yG) = (x1 + x2 + x3) / 3, (y1 + y2 + y3) / 3
void trongTam(toaDo a) {
    float xG = (a.x1 + a.x2 + a.x3) / 3;
    float yG = (a.y1 + a.y2 + a.y3) / 3;
    printf("\nTrọng tâm G của tam giác: G(%.2f, %.2f)", xG, yG);
}

// Hàm xuất kết quả ra màn hình
void xuat(toaDo a) {
    printf("\nChu vi tam giác: %.2f", chuVi(a));
    printf("\nDiện tích tam giác: %.2f", dienTich(a));
    trongTam(a);
}

int main() {
    toaDo a;
    nhap(&a);
    printf("\nTam giác có tọa độ 3 đỉnh là: A(%.2f,%.2f), B(%.2f,%.2f), C(%.2f,%.2f)",a.x1,a.y1,a.x2,a.y2,a.x3,a.y3);
    xuat(a);
    return 0;
}
