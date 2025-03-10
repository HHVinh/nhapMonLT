#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
            printf("Mẫu số phải khác 0. Nhập lại!");
        }
    }
    while(a->mauSo == 0);   
}

void xuatPhanSo(ps *a){
    printf("Phân số là: %.1f / %.1f", a->tuSo, a->mauSo);
}

int main(){
    
    ps a;
    nhapPhanSo(&a);
    xuatPhanSo(&a);

    return 0;
}