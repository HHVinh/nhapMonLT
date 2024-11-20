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

void ViTriSoAm(float a[100], int n){
    int found = 0;  // Biến để kiểm tra nếu có số chẵn
    printf("Vị trí các số < 0 là:\n");
    for (int i = 0; i < n; i++) {
        if (a[i] <= 0) {
            printf("Giá trị là %f - Vị trí là: %d\n", a[i], i);
            found = 1;  // Đánh dấu là có số chẵn
        }  
    }
    if (!found) {
        printf("Không có số < 0.");
    }
    printf("\n");
}

int main(){
    float a[100];
    int n;

    printf("Hãy nhập số lượng phần tử của mảng: ");
    scanf("%d",&n);

    NhapMang(a,n);
    XuatMang(a,n);

    ViTriSoAm(a,n);

    return 0;
}

