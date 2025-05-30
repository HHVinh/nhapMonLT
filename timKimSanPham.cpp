#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char maSP[20];
    char tenSP[100];
    int gia;
} SanPham;

void TimKiemSanPham(const char* duongDanTapTin, const char* tuKhoa) {
    FILE *f = fopen(duongDanTapTin, "r");
    if (f == NULL) {
        printf("Không thể mở file: %s\n", duongDanTapTin);
        return;
    }

    char dong[200];
    while (fgets(dong, sizeof(dong), f)) {
        // Xóa ký tự newline nếu có
        dong[strcspn(dong, "\n")] = '\0';

        SanPham sp;

        // Tách thông tin bằng dấu phẩy
        char *token = strtok(dong, ",");
        if (token) strcpy(sp.maSP, token);

        token = strtok(NULL, ",");
        if (token) strcpy(sp.tenSP, token);

        token = strtok(NULL, ",");
        if (token) sp.gia = atoi(token);

        // Tìm từ khóa trong tên sản phẩm (không phân biệt hoa thường nếu cần thì dùng strcasestr)
        if (strstr(sp.tenSP, tuKhoa)) {
            printf("%s, %s, %d\n", sp.maSP, sp.tenSP, sp.gia);
        }
    }

    fclose(f);
}

int main() {
    char tuKhoa[50];
    printf("Nhập từ khóa cần tìm: ");
    fflush(stdin);
    gets(tuKhoa); // dùng fgets nếu bạn học nâng cao hơn

    TimKiemSanPham("sanpham.txt", tuKhoa);

    return 0;
}
