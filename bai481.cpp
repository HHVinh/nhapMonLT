// Bài 481: Hãy khai báo kiểu dữ liệu biểu diễn ngày trong thế giới thực và định nghĩa hàm nhập, hàm xuất cho kiểu dữ liệu này
#include <stdio.h>

// Khai báo kiểu dữ liệu biểu diễn ngày
struct date {
    int ngay, thang, nam;
};

typedef struct date Date;

// Hàm kiểm tra năm nhuận
int kiemTraNamNhuan(int nam) {
    return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0));
}

// Hàm lấy số ngày tối đa của tháng
int soNgayTrongThang(int thang, int nam) {
    switch (thang) {
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return kiemTraNamNhuan(nam) ? 29 : 28;
        default:
            return 31;
    }
}

// Hàm nhập ngày với kiểm tra hợp lệ
void nhap(Date *a) {
    do {
        printf("Nhập năm: ");
        scanf("%d", &a->nam);
        if (a->nam < 1) {
            printf("⚠ Năm không hợp lệ! Vui lòng nhập lại.\n");
        }
    } while (a->nam < 1);

    do {
        printf("Nhập tháng: ");
        scanf("%d", &a->thang);
        if (a->thang < 1 || a->thang > 12) {
            printf("⚠ Tháng không hợp lệ! Vui lòng nhập lại (1-12).\n");
        }
    } while (a->thang < 1 || a->thang > 12);

    int maxNgay = soNgayTrongThang(a->thang, a->nam);
    do {
        printf("Nhập ngày: ");
        scanf("%d", &a->ngay);
        if (a->ngay < 1 || a->ngay > maxNgay) {
            printf("⚠ Ngày không hợp lệ! Vui lòng nhập lại (1-%d).\n", maxNgay);
        }
    } while (a->ngay < 1 || a->ngay > maxNgay);
}

// Hàm xuất ngày theo định dạng chuẩn
void xuat(Date a) {
    printf("📅 Ngày hợp lệ: %02d/%02d/%d\n", a.ngay, a.thang, a.nam);
}

// Hàm chính
int main() {
    Date ngay;
    nhap(&ngay);
    xuat(ngay);
    return 0;
}
