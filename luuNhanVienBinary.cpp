// Viết chương trình nhập n nhân viên (tên, mã, lương), lưu vào file "nhanvien.dat".
// Sau đó đọc lại và in ra các nhân viên có lương cao nhất.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char ten[50];
    char ma[20];
    float luong;
} NhanVien;

void nhapNhanVien(NhanVien *nv) {
    printf("Nhap ten: ");
    fflush(stdin); // Xóa bộ đệm trước khi nhập chuỗi
    gets(nv->ten);

    printf("Nhap ma: ");
    gets(nv->ma);

    printf("Nhap luong: ");
    scanf("%f", &nv->luong);
}

void ghiFile(NhanVien ds[], int n, const char *filename) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        printf("Khong mo duoc file!\n");
        return;
    }
    fwrite(ds, sizeof(NhanVien), n, f);
    fclose(f);
}

int docFile(NhanVien ds[], const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Khong mo duoc file!\n");
        return 0;
    }
    int i = 0;
    while (fread(&ds[i], sizeof(NhanVien), 1, f)) {
        i++;
    }
    fclose(f);
    return i;
}

void inNhanVien(NhanVien nv) {
    printf("Ten: %s\tMa: %s\tLuong: %.2f\n", nv.ten, nv.ma, nv.luong);
}

int main() {
    int n;
    NhanVien ds[MAX];

    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\n--- Nhan vien %d ---\n", i + 1);
        nhapNhanVien(&ds[i]);
    }

    ghiFile(ds, n, "nhanvien.dat");

    // Đọc lại từ file
    NhanVien danhSachDoc[MAX];
    int soLuong = docFile(danhSachDoc, "nhanvien.dat");

    // Tìm lương cao nhất
    float maxLuong = danhSachDoc[0].luong;
    for (int i = 1; i < soLuong; i++) {
        if (danhSachDoc[i].luong > maxLuong) {
            maxLuong = danhSachDoc[i].luong;
        }
    }

    // In các nhân viên có lương cao nhất
    printf("\nCac nhan vien co luong cao nhat (%.2f):\n", maxLuong);
    for (int i = 0; i < soLuong; i++) {
        if (danhSachDoc[i].luong == maxLuong) {
            inNhanVien(danhSachDoc[i]);
        }
    }

    return 0;
}
