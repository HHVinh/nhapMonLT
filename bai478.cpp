// Bài 478: Hãy khai báo kiểu dữ liệu biểu diễn khái niệm điểm trong không gian Oxyz và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include <stdio.h>
#include <stdlib.h>

struct diemTrongKhongGian {
    int toaDoX;
    int toaDoY;
    int toaDoZ;  // Thêm tọa độ Z
};

typedef struct diemTrongKhongGian td3D;

void nhapToaDo(td3D *a) {
    printf("\nNhập tọa độ X: "); scanf("%d", &a->toaDoX);
    printf("\nNhập tọa độ Y: "); scanf("%d", &a->toaDoY);
    printf("\nNhập tọa độ Z: "); scanf("%d", &a->toaDoZ);  // Nhập thêm Z
}

void inToaDo(td3D a) {
    printf("\nĐiểm có tọa độ trong không gian Oxyz là: (%d, %d, %d)", a.toaDoX, a.toaDoY, a.toaDoZ);
}

int main() {
    td3D a;
    nhapToaDo(&a);
    inToaDo(a);
    return 0;
}
