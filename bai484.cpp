#include <stdio.h>
#include <math.h> // Thêm thư viện để sử dụng M_PI (π)

// Định nghĩa struct đường tròn
typedef struct {
    float x0, y0; // Tọa độ tâm đường tròn
    float r;      // Bán kính đường tròn
} dt;

// Hàm nhập tọa độ tâm và bán kính của đường tròn
void nhap(dt *a) {
    printf("\nNhập x0, y0 của tâm đường tròn: ");
    scanf("%f%f", &a->x0, &a->y0);
    
    printf("\nNhập bán kính r của đường tròn: ");
    scanf("%f", &a->r);

    // Kiểm tra r phải lớn hơn 0
    while (a->r <= 0) {
        printf("\nBán kính đường tròn phải lớn hơn 0. Nhập lại: ");
        scanf("%f", &a->r);
    }
}

// Hàm xuất chu vi và diện tích đường tròn với chú thích chi tiết
void xuat(dt a) {
    float chuVi = 2 * M_PI * a.r;   // Công thức: C = 2πr
    float dienTich = M_PI * a.r * a.r; // Công thức: S = πr²

    printf("\nChu vi đường tròn tâm (%.2f, %.2f) là: %.2f (đơn vị chiều dài)", a.x0, a.y0, chuVi);
    printf("\nDiện tích đường tròn tâm (%.2f, %.2f) là: %.2f (đơn vị diện tích)", a.x0, a.y0, dienTich);
}

int main() {
    dt a;  // Khai báo biến đường tròn

    nhap(&a); // Nhập dữ liệu đường tròn
    xuat(a);  // Xuất kết quả chu vi & diện tích

    return 0;
}
