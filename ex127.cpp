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

void XepMangTang(int a[100], int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void XepMangGiam(int a[100], int n){
    for (int i = 0; i < n - 1; i++)
    {
        int MinInd = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] > a[MinInd])
            {
                MinInd = j;
            } 
        }
        if (MinInd != i)
        {
            int temp = a[i];
            a[i] = a[MinInd];
            a[MinInd] = temp;
        }
    }
}

int main(){
    int a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    XepMangTang(a,n);
    printf("Kết quả là: ");
    XuatMang(a,n);

    XepMangGiam(a,n);
    printf("Kết quả là: ");
    XuatMang(a,n);

    return 0;
}

