#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include <math.h>
// Bài 476: Hãy khai báo kiểu dữ liệu biểu diễn khái niệm hỗn số trong toán học và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này

struct honSo{
    int nguyen;
    float tu, mau;
};

typedef struct honSo hs;

void nhap(hs *a){
    printf("Nhập tử số: "); scanf("%f", &a->tu);
    do{
        printf("Nhập mãu số: "); scanf("%f", &a->mau);
        if(a->mau == 0){
            printf("Nhập lại, mẫu phải khác 0.\n");
        }
    }
    while(a->mau == 0);
}

void xuat(hs a) {
    // Xử lý dấu
    int laSoAm = (a.tu < 0) ^ (a.mau < 0);  // XOR để kiểm tra nếu chỉ một trong hai số âm

    // Đảm bảo tử và mẫu luôn dương để dễ xử lý
    a.tu = fabs(a.tu);
    a.mau = fabs(a.mau);

    // Tính phần nguyên
    a.nguyen = (int)(a.tu / a.mau);
    a.tu = fabs(a.tu - a.nguyen * a.mau);  // Cập nhật lại tử số

    // Xuất kết quả
    if (a.tu == 0) {
        // Nếu không có phần phân số
        printf("Hỗn số là: %s%d\n", laSoAm ? "-" : "", a.nguyen);
    } else if (a.nguyen == 0) {
        // Nếu không có phần nguyên
        printf("Hỗn số là: %s%.1f/%.1f\n", laSoAm ? "-" : "", a.tu, a.mau);
    } else {
        // Nếu có cả phần nguyên và phần phân số
        printf("Hỗn số là: %s%d(%.1f/%.1f)\n", laSoAm ? "-" : "", a.nguyen, a.tu, a.mau);
    }
}

int main() {
    hs a;
    nhap(&a);
    xuat(a);
    return 0;
}