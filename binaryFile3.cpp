// Viết chương trình cho phép:
// Nhập n nhân viên từ bàn phím (họ tên, tuổi, lương) → lưu vào file nhị phân "nhanvien.dat"
// Đọc file "nhanvien.dat" và in ra các nhân viên có lương cao nhất.
// Yêu cầu:
// Sử dụng struct để quản lý thông tin nhân viên.
// Dùng fwrite, fread để thao tác với file nhị phân.

#include <stdio.h>
#include <string.h>

typedef struct Nhanvien{
    char Hoten[30];
    int Tuoi;
    float Luong;
} Nhanvien;

void ghiFile(){

    FILE* f = fopen("binaryFile3.bin", "wb");
    if(!f){
        printf("Không mở được file");
        return;
    }

    Nhanvien nv;
    int n;
    printf("Nhập số lượng nhân viên: "); scanf("%d",&n);
    while (getchar() != '\n');

    for(int i = 0; i < n; i++){
        printf("Nhập nhân viên %d: \n", i+1);
        printf("Nhập họ tên: ");
        fgets(nv.Hoten, sizeof(nv.Hoten), stdin);
        nv.Hoten[strcspn(nv.Hoten, "\n")] = 0;
        printf("Nhập tuổi: "); scanf("%d", &nv.Tuoi);
        printf("Nhập lương: "); scanf("%f", &nv.Luong);
        while (getchar() != '\n');

        fwrite(&nv, sizeof(nv), 1, f);
    }
    fclose(f);
}

void docFile(){
    FILE* f = fopen("binaryFile3.bin", "rb");
    if(!f){
        printf("Không mở được file");
    }

    Nhanvien nv;
    printf("Thông tin nhân viên: \n");
    int i = 1;
    while(fread(&nv, sizeof(nv), 1, f) == 1){
        printf("Nhân viên %d: Họ và tên: %s, Tuổi: %d, Lương: %.2f\n", i, nv.Hoten, nv.Tuoi, nv.Luong);
        i++;
    }

    fclose(f);
}

int main(){
    ghiFile();
    docFile();

    return 0;
}