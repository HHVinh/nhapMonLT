#include <stdio.h>
#include <math.h>
// Bài 475: Hãy khai báo kiểu dữ liệu biểu diễn khái niệm phân số trong toán học và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này

struct phanSo{
    float tuSo;
    float mauSo;
};

typedef struct phanSo ps;

void nhapPhanSo(ps *a){
    printf("Nhập tử số: "); scanf("%f", &a->tuSo);
    do{
        printf("Nhập mẫu số: "); scanf("%f", &a->mauSo);
        if(a->mauSo == 0){
            printf("Mẫu số phải khác 0. Nhập lại!\n");
        }
    } while(a->mauSo == 0);   
}

void xuatPhanSo(ps a){  // Sửa thành truyền tham trị, vì a không cần dùng con trỏ
    if( a.tuSo == 0) printf("Phân số là 0\n");
    if (a.mauSo <0) printf("Phân số là: -%.1f / %.1f\n", a.tuSo, fabs(a.mauSo));  // Thêm \n
    else printf("Phân số là: %.1f / %.1f\n", a.tuSo, a.mauSo);  // Thêm \n
}

int main(){
    ps a;
    nhapPhanSo(&a);
    xuatPhanSo(a);  // Truyền tham trị (bỏ dấu &)

    return 0;
}
