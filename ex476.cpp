#include <stdio.h>

typedef struct {
    int PhanNguyen; 
    int TuSo; 
    int MauSo;
} HonSo;

void NhapHonSo(HonSo *hs) {
    printf("Nhập phần nguyên: "); 
    scanf("%d", &hs->PhanNguyen);

    printf("Nhập tử số: "); 
    scanf("%d", &hs->TuSo);

    do {
        printf("Nhập mẫu số: "); 
        scanf("%d", &hs->MauSo);
        if (hs->MauSo == 0) {
            printf("Mẫu số phải khác không. Nhập lại!\n");
        }
    } while (hs->MauSo == 0);
}

void XuatHonSo(const HonSo *hs) {
    // Trường hợp phần nguyên là 0
    if (hs->PhanNguyen == 0) {
        if (hs->MauSo == 1) {
            printf("Phân số là: %d\n", hs->TuSo); // Nếu mẫu số là 1, chỉ hiển thị tử số
        } else {
            printf("Phân số là: %d/%d\n", hs->TuSo, hs->MauSo); // Phân số đơn thuần
        }
    } 
    // Trường hợp phần nguyên khác 0
    else {
        if (hs->TuSo == 0) {
            printf("Hỗn số là: %d\n", hs->PhanNguyen); // Nếu tử số là 0, chỉ hiển thị phần nguyên
        } else {
            printf("Hỗn số là: %d(%d/%d)\n", hs->PhanNguyen, hs->TuSo, hs->MauSo);
        }
    }
}

int main() {
    HonSo hs;
    NhapHonSo(&hs);
    XuatHonSo(&hs);
    return 0;
}
