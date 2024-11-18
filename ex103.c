#include <stdio.h>

int kiemTraNamNhuan(int nam){
    if((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0){
        return 1;
    }
    return 0;
}

int soNgay (int thang, int nam){
    if(thang == 2){
        if (kiemTraNamNhuan(nam))
        {
            return 29;
        }
        return 28;
    }
    else if ((thang <=7 && thang % 2 == 0) || thang >= 8 && thang % 2 == 1)
    {
        return 30; 
    }
    return 31;
}

void ngayTruoc(int *ngay, int *thang, int *nam) {
    if (*ngay == 1) {  // Nếu là ngày đầu tháng
        if (*thang == 1) {  // Nếu là tháng 1, phải chuyển sang tháng 12 năm trước
            *thang = 12;
            *nam -= 1;
        } else {  // Ngược lại, chỉ giảm tháng đi 1
            *thang -= 1;
        }
        *ngay = soNgay(*thang, *nam);  // Gán ngày thành số ngày của tháng trước
    } else {  // Ngày bình thường, chỉ giảm 1 ngày
        *ngay -= 1;
    }
}


int main() {
    int ngay, thang, nam;

    printf("Nhập ngày tháng năm (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &ngay,&thang,&nam);
    if (ngay<1 || ngay > soNgay(thang,nam) || thang <1 || thang >12 || nam < 0)
    {
        printf("Ngày tháng năm bạn nhập chưa hợp lệ!");
    }else{
        ngayTruoc(&ngay,&thang,&nam);
        printf("Ngày tiếp theo là: %d/%d/%d",ngay,thang,nam);
    }
    return 0;
}
