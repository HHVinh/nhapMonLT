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

void LietKeSoChan(int a[100], int n){
    int found = 0;  // Biến để kiểm tra nếu có số chẵn
    printf("Các số chẵn trong mảng là: ");
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            printf("%2d ", a[i]);
            found = 1;  // Đánh dấu là có số chẵn
        }  
    }
    if (!found) {
        printf("Không có số chẵn trong mảng.");
    }
    printf("\n");
}

int main(){
    int a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    LietKeSoChan(a,n);

    return 0;
}

