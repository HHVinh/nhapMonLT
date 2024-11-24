#include <stdio.h>

// Khai báo struct PhanSo
typedef struct {
    int tuso;
    int mauso;
} PhanSo;

// Hàm nhập mảng phân số
void NhapMangPhanSo(PhanSo ps[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhập tử số %d: ", i + 1);
        scanf("%d", &ps[i].tuso);
        do {
            printf("Nhập mẫu số %d: ", i + 1);
            scanf("%d", &ps[i].mauso);
            if (ps[i].mauso == 0) {
                printf("Mẫu số phải khác 0, vui lòng nhập lại.\n");
            }
        } while (ps[i].mauso == 0);
    }
}

// Hàm xuất mảng phân số
void XuatMangPhanSo(PhanSo ps[], int n) {
    printf("Danh sách phân số:\n");
    for (int i = 0; i < n; i++) {
        printf("%d/%d ", ps[i].tuso, ps[i].mauso);
    }
    printf("\n");
}

int main() {
    int n;

    // Nhập số lượng phân số
    printf("Nhập số lượng phân số: ");
    scanf("%d", &n);

    // Kiểm tra số lượng hợp lệ
    if (n <= 0 || n > 10) {
        printf("Số lượng phân số phải lớn hơn 0 và nhỏ hơn hoặc bằng 10.\n");
        return 1;
    }

    PhanSo ps[10]; // Mảng chứa tối đa 10 phân số
    NhapMangPhanSo(ps, n); // Nhập mảng phân số
    XuatMangPhanSo(ps, n); // Xuất mảng phân số

    return 0;
}
