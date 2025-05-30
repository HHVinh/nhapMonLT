#include <stdio.h>
#include <string.h>

typedef struct Nhanvien {
    char hoTen[30];
    int tuoi;
    int luong;
} Nhanvien;

void ghiFile() {
    int n;
    printf("Nhap so luong nhan vien: ");
    scanf("%d", &n);
    getchar();  // loại bỏ ký tự '\n' còn sót lại sau scanf

    FILE* f = fopen("DSNV.bin", "wb");
    if (f == NULL) {
        printf("Khong mo duoc file\n");
        return;
    }

    Nhanvien nv;
    for (int i = 0; i < n; i++) {
        printf("Nhap nhan vien %d:\n", i + 1);

        printf("Ho ten: ");
        fgets(nv.hoTen, sizeof(nv.hoTen), stdin);
        // loại bỏ ký tự '\n' cuối chuỗi nếu có
        nv.hoTen[strcspn(nv.hoTen, "\n")] = 0;

        printf("Tuoi: ");
        scanf("%d", &nv.tuoi);

        printf("Luong: ");
        scanf("%d", &nv.luong);

        getchar();  // loại bỏ ký tự '\n' còn sót lại sau scanf

        fwrite(&nv, sizeof(Nhanvien), 1, f);
    }

    fclose(f);
    printf("Ghi file thanh cong!\n");
}

void docFile() {
    FILE* f = fopen("DSNV.bin", "rb");
    if (f == NULL) {
        printf("Khong mo duoc file\n");
        return;
    }

    Nhanvien nv;
    printf("Danh sach nhan vien:\n");
    while (fread(&nv, sizeof(Nhanvien), 1, f) == 1) {
        printf("Ho ten: %s, Tuoi: %d, Luong: %d\n", nv.hoTen, nv.tuoi, nv.luong);
    }

    fclose(f);
}

int main() {
    ghiFile();
    docFile();
    return 0;
}
