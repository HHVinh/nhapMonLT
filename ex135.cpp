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

void GiaTriDuong(float a[100], int n){
    int Index = 0;
    float teamp = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            teamp = a[i];
            Index = i;
            break;
        }  
    }
    if(teamp > 0){
        printf("Giá trị dương đầu tiên là %f - Vị trí là: %d\n", teamp, Index);
    } else{
        printf("-1");
    }
}

int main(){
    float a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    GiaTriDuong(a,n);

    return 0;
}

