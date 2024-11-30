#include <stdio.h>

void Nhap(int m, int n, int a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("Nhập giá trị của hàng %d - cột %d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void Xuat(int m, int n, int a[100][100]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

void TinhTich1Cot(int m, int n, int a[100][100]){
    for(int j = 0; j<n; j++){
        int Tong = 1; int Dem = 0;
        for(int i = 0; i<m; i++){
            if(a[i][j] % 2 == 0){
                Tong *= a[i][j]; Dem +=1;
            }
        }
        if(Dem == 0){
            Tong = 0;
        }
        printf("Tích số chẵn cột %d là: %d\n",j+1, Tong);
    }
}

int main(){
    int m, n; int a[100][100];
    printf("Nhập số hàng và cột của mảng hai chiều MxN: ");
    scanf("%d %d",&m,&n);

    Nhap(m,n,a);
    printf("Mảng vừa nhập là:\n");
    Xuat(m,n,a);
    printf("\n Kết quả là: \n");
    TinhTich1Cot(m,n,a);

}