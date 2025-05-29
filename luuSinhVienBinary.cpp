// Viết chương trình lưu danh sách n sinh viên (gồm tên, MSSV, điểm) vào file nhị phân "sinhvien.dat".
// Sau đó đọc lại file và in ra các sinh viên có điểm >= 8.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char ten[50];
    char mssv[20];
    float diem;
} SinhVien;

// Hàm nhập danh sách sinh viên
void nhapDanhSach(SinhVien* ds, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien %d:\n", i + 1);
        printf("Ten: ");
        getchar(); // Xóa ký tự '\n' còn sót
        fgets(ds[i].ten, sizeof(ds[i].ten), stdin);
        ds[i].ten[strcspn(ds[i].ten, "\n")] = '\0';

        printf("MSSV: ");
        fgets(ds[i].mssv, sizeof(ds[i].mssv), stdin);
        ds[i].mssv[strcspn(ds[i].mssv, "\n")] = '\0';

        printf("Diem: ");
        scanf("%f", &ds[i].diem);
    }
}

// Hàm ghi vào file nhị phân
void ghiFile(SinhVien* ds, int n, const char* tenFile) {
    FILE* f = fopen(tenFile, "wb");
    if (f == NULL) {
        printf("Khong mo duoc file de ghi!\n");
        exit(1);
    }

    fwrite(ds, sizeof(SinhVien), n, f);
    fclose(f);
}

// Hàm đọc và in sinh viên có điểm >= 8
void docVaInSinhVienGioi(const char* tenFile) {
    FILE* f = fopen(tenFile, "rb");
    if (f == NULL) {
        printf("Khong mo duoc file de doc!\n");
        exit(1);
    }

    SinhVien sv;
    printf("\nCac sinh vien co diem >= 8:\n");
    while (fread(&sv, sizeof(SinhVien), 1, f) == 1) {
        if (sv.diem >= 8.0) {
            printf("Ten: %s\n", sv.ten);
            printf("MSSV: %s\n", sv.mssv);
            printf("Diem: %.2f\n\n", sv.diem);
        }
    }

    fclose(f);
}

int main() {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    SinhVien* ds = (SinhVien*) malloc(n * sizeof(SinhVien));
    if (ds == NULL) {
        printf("Loi cap phat bo nho!\n");
        return 1;
    }

    nhapDanhSach(ds, n);
    ghiFile(ds, n, "sinhvien.dat");
    free(ds);

    docVaInSinhVienGioi("sinhvien.dat");

    return 0;
}
