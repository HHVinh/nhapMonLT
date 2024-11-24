#include <stdio.h>

void NhapMaTran(int m ,int n, int MaTran[100][100]){
    for(int i = 0; i<m;i++){
        for(int j = 0; j<n;j++){
            printf("Hãy nhập giá trị tại dòng %d - cột %d: ", i+1, j+1);
            scanf("%d", &MaTran[i][j]);
        }
    }
}

void XuatMaTran(int m, int n, int MaTran[100][100]){
    for(int i =0; i<m;i++){
        for(int j = 0; j<n;j++){
            printf("%d ", MaTran[i][j]);
        }
        printf("\n");
    }
}

int DemPhanTuDuong(int m, int n, int MaTran[100][100]){
    int dem = 0; int tong =0;
    // Duyệt hàng 1 và hàng cuối
    for (int j = 0; j < n; j++)
    {
       if (MaTran[0][j]>0)
       {
            dem +=1;
       }
       if (m>1 && MaTran[m-1][j]>0)
       {
            dem +=1;
       }
    }
    // Duyệt cột đầu đầu và cột cuối
    for(int i = 1; i <m-1;i++){
        if(MaTran[i][0]>0){
            dem +=1;
        }
        if(n>1 && MaTran[i][n-1]>0){
            dem +=1;
        }
    }
    return dem;
}
    
int main(){
    int m,n;
    int MaTran[100][100];

    printf("Hãy nhập số hàng và cột của ma trận: ");
    scanf("%d %d",&m, &n);

    NhapMaTran(m,n,MaTran);
    XuatMaTran(m,n,MaTran);
    int KetQua = DemPhanTuDuong(m,n,MaTran);
    printf("Kết quả là: %d", KetQua);

    return 0;
}

