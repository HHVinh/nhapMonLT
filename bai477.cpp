// Bài 477: Hãy khai báo kiểu dữ liệu biểu diễn khái niệm điểm trong mặt phẳng Oxy và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct diemTrenMatPhang{
    int toaDoX;
    int toaDoY;
};

typedef struct diemTrenMatPhang td;

void nhapToaDo(td *a){
    printf("\nNhập tọa độ X: "); scanf("%d", &a->toaDoX);
    printf("\nNhập tọa độ Y: "); scanf("%d", &a->toaDoY);
}

void inToaDo(td a){
    printf("\nĐiểm có tọa độ trên mặt phẳng Oxy là: (%d, %d)", a.toaDoX, a.toaDoY);
}

int main(){

    td a;
    nhapToaDo(&a);
    inToaDo(a);

    return 0;
}