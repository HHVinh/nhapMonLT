#include <stdio.h>

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

int TongSoAm(int a[100], int n){
    int Tong = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            Tong += a[i];
        }  
    }
    return Tong;
}

int main(){
    int a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    int KetQua = TongSoAm(a,n);
    printf("Kết quả là: %d", KetQua);

    return 0;
}

