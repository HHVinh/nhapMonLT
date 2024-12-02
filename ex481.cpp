#include <stdio.h>

typedef struct {
    int ngay;int thang; int nam;
} Date;

int KiemTraNamNhuan(int nam){
    if((nam %4 == 0 && nam % 100 != 0) || nam % 400 == 0){
        return 1;
    }
    return 0;
}

void NhapDate(Date *n){
    printf("Nhập ngày/tháng/năm: "); scanf("%d/%d/%d", &n->ngay,&n->thang,&n->nam);

    if(n->nam <= 0){
        printf("Năm không hợp lệ");
        return;
    }
    if(n->thang <1 || n->thang >12){
        printf("Tháng không hợp lệ");
        return;
    }
    int Maxngay;
    switch (n->thang){
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        Maxngay = 31;
        break;
    case 4: case 6: case 9: case 11:
        Maxngay = 30;
        break;
    case 2:
        if(KiemTraNamNhuan(n->nam)){
            Maxngay = 29;
        } else {
            Maxngay = 28;
        }
        break;
    default:
        printf("Tháng không hợp lệ!\n");
        return;
        break;
    }
    if(n->ngay < 1 || n->ngay > Maxngay){
        printf("Ngày không hợp lệ!\n");
    }
}

void XuatNgay(Date *n){
    printf("Ngày: %d/%d/%d", n->ngay, n->thang, n->nam);
}

int main(){
    Date n;
    NhapDate(&n);
    XuatNgay(&n);
    return 0;
}

