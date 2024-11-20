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

int ViTriGiaTriNhoNhat(int a[100], int n, int *MinValue){
    *MinValue = a[0];
    int MinIndex = 0;
    for (int i = 1; i < n; i++)
    {
        if (*MinValue > a[i])
        {
            *MinValue = a[i];
            MinIndex = i;
        }  
    }
    return MinIndex;
}

int main(){
    int a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    int MinValue;
    int MinIndex = ViTriGiaTriNhoNhat(a,n, &MinValue);
    printf("Giá trị nhỏ nhất của mảng là: %d tại vị trí: %d\n", MinValue, MinIndex);

    return 0;
}
