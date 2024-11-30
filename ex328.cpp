#include <stdio.h>
#include <math.h> // Để sử dụng hàm pow()

void Nhap(int m, int n, float a[100][100]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Nhập giá trị của hàng %d - cột %d: ", i + 1, j + 1);
            scanf("%f", &a[i][j]);
        }
    }
}

void Xuat(int m, int n, float a[100][100]){
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%.2f ", a[i][j]);
        }
        printf("\n");
    }
}

float TinhTrungBinhNhanSoDuong(int m, int n, float a[100][100]){
    float Tich = 1;
    int Dem = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] > 0){
                Tich *= a[i][j];
                Dem++;
            }
        }
    }

    if(Dem == 0) {
        printf("\nKhông có số dương trong mảng.\n");
        return -1; // Trả về -1 nếu không có số dương
    }

    // Trung bình nhân là căn bậc Dem của Tich
    return pow(Tich, 1.0 / Dem);
}

int main(){
    int m, n;
    float a[100][100];

    printf("Nhập số hàng và cột của mảng hai chiều MxN: ");
    scanf("%d %d", &m, &n);

    Nhap(m, n, a);
    printf("\nMảng vừa nhập là:\n");
    Xuat(m, n, a);

    float KetQua = TinhTrungBinhNhanSoDuong(m, n, a);
    if(KetQua != -1) {
        printf("\nTrung bình nhân của các số dương là: %.2f\n", KetQua);
    }

    return 0;
}
