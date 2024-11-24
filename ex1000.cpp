#include <stdio.h>

// Khai báo struct PhanSo
typedef struct{
    int tu, mau;} Phanso;

void NhapMang(Phanso ps[], int n){
    for(int i = 0; i<n; i++){
        printf("Nhap tử %d: ", i+1);
        scanf("%d", ps[i].tu);
        do
        {
            printf("Nhap mẫu %d: ", i+1);
            scanf("%d", ps[i].mau);
            if(ps[i].mau == 0){
                
            }
        } while (ps[i].mau == 0);
        
    }
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

    Phanso ps[10]; // Mảng chứa tối đa 10 phân số
    NhapMang(ps, n); // Nhập mảng phân số
    //XuatMangPhanSo(ps, n); // Xuất mảng phân số

    return 0;
}
