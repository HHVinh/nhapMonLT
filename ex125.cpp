#include <stdio.h>
#include <math.h>

void NhapMang(int a[100], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nhập giá trị tại A[%d]: ", i);
        scanf("%d", &a[i]);
    }
}

void XuatMang(int a[100],int n){
    printf("Mảng vừa nhập là:");
    for (int i = 0; i < n; i++)
    {
        printf("%5d", a[i]);
    }
    printf("\n");
}

bool KiemTraSoNguyenTo(int n) {
    if (n <= 1)
        return false;
    if (n == 2) // 2 là số nguyên tố
        return true;
    if (n % 2 == 0) // Số chẵn lớn hơn 2 không phải số nguyên tố
        return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}


int DemSoLuongSoNguyenTo(int a[100], int n){
    int Dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (KiemTraSoNguyenTo(a[i]) && a[i] < 100)
        {
            Dem ++;
        }  
    }
    return Dem;
}

int main(){
    int a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    int KetQua = DemSoLuongSoNguyenTo(a,n);
    printf("Số lượng các số nguyên tố < 100 trong mảng là: %d", KetQua);

    return 0;
}