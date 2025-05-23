// Bài 327: Tính tổng các giá trị nằm trên biên của ma trận
#include <stdio.h>
#include <stdlib.h>

void nhapMang(int **arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            printf("Nhập phần tử A[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void xuatMang(int **arr, int n, int m){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
}

int tongBien(int** arr, int n, int m){
    int tong = 0;

    // Dòng đầu và dòng cuối
    for(int j = 0; j < m; j++){
        tong += arr[0][j];              // dòng đầu
        if(n > 1) tong += arr[n-1][j];  // dòng cuối (nếu khác dòng đầu)
    }

    // Cột đầu và cột cuối (trừ dòng đầu và cuối đã cộng rồi)
    for(int i = 1; i < n - 1; i++){
        tong += arr[i][0];              // cột đầu
        if(m > 1) tong += arr[i][m-1];  // cột cuối (nếu khác cột đầu)
    }

    return tong;
}


int main(){
    int n, m;
    printf("Nhập số lượng dòng và cột: ");
    scanf("%d%d", &n,&m);

    int **arr = (int **) malloc(n * sizeof(int*));
    if(arr == NULL){
        printf("Lỗi!");
        return 1;
    }
    for(int i = 0; i < n; i++){
        arr[i] = (int*) malloc(m * sizeof(int));
        if(arr[i] == NULL){
        printf("Lỗi!");
        // Giải phóng các dòng đã cấp phát trước đó
        for (int j = 0; j < i; j++) {
            free(arr[j]);
        }
        free(arr);
        return 1;
        }
    }

    nhapMang(arr, n, m);
    printf("\nMa trận vừa nhập là: \n");
    xuatMang(arr, n, m);
    
    int ketQua = tongBien(arr, n, m);
    printf("\n Tổng biên ma trận là: %d", ketQua);

    for(int i = 0; i < n; i++){
        free(arr[i]);
        }
    free(arr);
    return 0;
}