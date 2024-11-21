#include <stdio.h>

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

void GiaTriLonNhat(float a[100], int n){
    float teamp = a[0];
    int Index = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > teamp) {
            teamp = a[i];
            Index = i;
        }  
    }
    printf("Giá trị lớn nhất là %f - Vị trí là: %d\n", teamp, Index);
}

int main(){
    float a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    GiaTriLonNhat(a,n);

    return 0;
}

