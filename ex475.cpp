#include <stdio.h>

typedef struct
{
    int tuso; int mauso;
} PhanSo;

void NhapPhanSo(PhanSo *ps){
    printf("Nhập tử số: "); scanf("%d", &ps->tuso);
    do{
        printf("Nhập mẫu số: "); scanf("%d", &ps->mauso);
        if(ps->mauso == 0){
            printf("Mẫu số khác không. Vui lòng nhập lại! \n");
        }
    } while (ps->mauso == 0);  
}

void XuatPhanSo(PhanSo ps){
    if(ps.mauso ==0){
        printf("Phân số: %d\n", ps.tuso);
    } else {
        printf("Phân số: %d/%d\n", ps.tuso, ps.mauso);
    }
}

int main(){
    PhanSo ps;
    NhapPhanSo(&ps);
    XuatPhanSo(ps);
}