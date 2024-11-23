#include <stdio.h>
#include <math.h>  
void NhapMang(float a[100], int n){
    for (int i = 0; i < n; i++)
    {
        printf("Nhập giá trị tại A[%d]: ", i);
        scanf("%f", &a[i]);
    }
}

void XuatMang(float a[100],int n){
    printf("Mảng vừa nhập là: ");
    for (int i = 0; i < n; i++)
    {
        printf("%f   ", a[i]);
    }
    printf("\n");
}

int GiaTriXaNhat(float a[100], int n, float x){
    float KetQua = 0;
    float Value = 0;
    for (int i = 0; i < n; i++) {
        if (abs(a[i] - x) > Value) {
            Value = abs(a[i] - x);
            KetQua = a[i];
        }
    }
    return KetQua;  
}

int main(){
    float a[100], x;
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    printf("Hãy nhập x: ");
    scanf("%f",&x);

    float KetQua = GiaTriXaNhat(a,n,x);
    printf("Số xa %f nhất là %f", x, KetQua);

    return 0;
}

