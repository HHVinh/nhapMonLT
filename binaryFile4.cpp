// Viết chương trình quản lý sản phẩm gồm mã SP (char[10]), tên SP (char[30]), giá (float).
// Nhập n sản phẩm từ bàn phím và ghi vào file nhị phân sanpham.bin.
// Đọc từ file và in ra các sản phẩm có giá trên 1 triệu.
// Yêu cầu dùng fwrite, fread, và struct.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sanpham {
    char Masp[11];
    char Tensp[31];
    float Gia;
} Sanpham;

void ghiFile() {
    FILE* f = fopen("sanpham.bin", "wb");
    if (!f) {
        printf("Không mở được file\n");
        return;
    }

    int n;
    printf("Nhập số lượng sản phẩm: ");
    scanf("%d", &n);
    while (getchar() != '\n');  // Xóa bộ đệm

    Sanpham sp;
    for (int i = 0; i < n; i++) {
        printf("\nNhập sản phẩm %d:\n", i + 1);

        printf("Mã sản phẩm: ");
        fgets(sp.Masp, sizeof(sp.Masp), stdin);
        sp.Masp[strcspn(sp.Masp, "\n")] = 0;

        printf("Tên sản phẩm: ");
        fgets(sp.Tensp, sizeof(sp.Tensp), stdin);
        sp.Tensp[strcspn(sp.Tensp, "\n")] = 0;

        printf("Giá sản phẩm: ");
        scanf("%f", &sp.Gia);
        while (getchar() != '\n');  // Xóa bộ đệm

        fwrite(&sp, sizeof(sp), 1, f);
    }

    fclose(f);
}

void docFileVaInSPGiaTren1Trieu() {
    FILE* f = fopen("sanpham.bin", "rb");
    if (!f) {
        printf("Không mở được file\n");
        return;
    }

    Sanpham sp;
    int i = 1;
    printf("\nCác sản phẩm có giá trên 1 triệu:\n");
    while (fread(&sp, sizeof(sp), 1, f) == 1) {
        if (sp.Gia > 1000000) {
            printf("%d/ Mã SP: %s, Tên SP: %s, Giá: %.2f\n", i, sp.Masp, sp.Tensp, sp.Gia);
            i++;
        }
    }

    fclose(f);
}

int main() {
    ghiFile();
    docFileVaInSPGiaTren1Trieu();
    return 0;
}
