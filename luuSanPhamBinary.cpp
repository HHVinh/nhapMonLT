// Cho struct SanPham gồm mã, tên, giá. Viết chương trình ghi n sản phẩm vào file "sanpham.dat"
// và đọc lại toàn bộ sản phẩm có giá trong khoảng 100k–500k.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Sanpham {
    char Masp[5];
    char Tensp[50];
    int Gia;
} sp;

void ghiFile(sp* ds, int n, const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Lỗi mở file để ghi.\n");
        exit(1);
    }

    fwrite(ds, sizeof(sp), n, f);
    fclose(f);
}

void docVaIn(sp* ds, int n, const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Lỗi mở file để đọc.\n");
        exit(1);
    }

    sp temp;
    printf("\nCác sản phẩm có giá từ 100000 đến 500000:\n");
    while (fread(&temp, sizeof(sp), 1, f) == 1) {
        if (temp.Gia >= 100000 && temp.Gia <= 500000) {
            printf("Ma: %s, Ten: %s, Gia: %d\n", temp.Masp, temp.Tensp, temp.Gia);
        }
    }

    fclose(f);
}

int main() {
    int n;
    printf("Nhap so luong san pham: ");
    scanf("%d", &n);

    sp* ds = (sp*)malloc(n * sizeof(sp));
    if (ds == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("\nSan pham thu %d:\n", i + 1);
        printf("Ma: ");
        scanf("%s", ds[i].Masp);
        printf("Ten: ");
        getchar(); // loại bỏ ký tự '\n' còn lại
        fgets(ds[i].Tensp, sizeof(ds[i].Tensp), stdin);
        ds[i].Tensp[strcspn(ds[i].Tensp, "\n")] = '\0'; // xóa newline nếu có
        printf("Gia: ");
        scanf("%d", &ds[i].Gia);
    }

    ghiFile(ds, n, "sanpham.dat");
    docVaIn(ds, n, "sanpham.dat");

    free(ds);
    return 0;
}
