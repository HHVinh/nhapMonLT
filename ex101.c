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

int main() {
    int thang, nam;

    printf("Nhập tháng: ");
    scanf("%d", &thang);
     printf("Nhập năm: ");
    scanf("%d", &nam);

    int ketQua = soNgay(thang,nam);
    printf("Tháng %d/%d có %d ngày!", thang,nam,ketQua);
    return 0;
}
