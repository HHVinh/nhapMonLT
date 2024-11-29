#include <stdio.h>

struct Date
{
   int Ngay, Thang, Nam;
};

void NhapDate(struct Date &d){
    printf("Nhập ngày/tháng/năm: ");
    scanf("%d/%d/%d",&d.Ngay, &d.Thang, &d.Nam);
}

void XuatNgay(struct Date &d){
    printf("Ngày vừa nhập là: %d/%d/%d", d.Ngay, d.Thang, d.Nam);
}

int main(){
    struct Date a;
    NhapDate(a);
    printf("\n");
    XuatNgay(a);

}