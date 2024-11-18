#include <stdio.h>

int kiemTraNamNhuan(int nam) {
    if ((nam % 4 == 0 && nam % 100 != 0) || nam % 400 == 0) {
        return 1;  // Năm nhuận
    }
    return 0;  // Không phải năm nhuận
}

int soNgay(int thang, int nam) {
    // Kiểm tra số ngày của các tháng
    if (thang == 2) {  // Tháng 2
        if (kiemTraNamNhuan(nam)) {
            return 29;  // Năm nhuận có 29 ngày
        }
        return 28;  // Năm không nhuận có 28 ngày
    } else if (thang == 4 || thang == 6 || thang == 9 || thang == 11) {  // Các tháng 30 ngày
        return 30;
    }
    return 31;  // Các tháng còn lại có 31 ngày
}

int tongNgayTrongNam(int ngay, int thang, int nam) {
    int tongNgay = 0;

    // Cộng số ngày trong các tháng trước tháng đã cho
    for (int i = 1; i < thang; i++) {
        tongNgay += soNgay(i, nam);
    }

    // Thêm ngày trong tháng hiện tại
    tongNgay += ngay;

    return tongNgay;  // Trả về tổng số ngày trong năm
}

int main() {
    int ngay, thang, nam;

    printf("Nhập ngày tháng năm (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &ngay, &thang, &nam);

    // Kiểm tra tính hợp lệ của ngày tháng năm
    if (ngay < 1 || ngay > soNgay(thang, nam) || thang < 1 || thang > 12 || nam < 0) {
        printf("Ngày tháng năm bạn nhập chưa hợp lệ!\n");
    } else {
        int ketQua = tongNgayTrongNam(ngay, thang, nam);
        printf("%d/%d/%d là ngày %d trong năm!\n", ngay, thang, nam, ketQua);
    }

    return 0;
}
