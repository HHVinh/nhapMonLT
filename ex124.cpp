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

bool KiemTraSoNguyenChanNhoHon2004(int a[100], int n){
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] < 2004)
        {
            return true;
        }
    }
    return false;
}

int main(){
    int a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    if (KiemTraSoNguyenChanNhoHon2004(a,n))
    {
        printf("Có số nguyên chẵn nhỏ hơn 2004");
    }
    else{
        printf("Không có số nguyên chẵn nhỏ hơn 2004");
    }
    return 0;
}