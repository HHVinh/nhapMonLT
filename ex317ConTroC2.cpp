// Bài 317: Viết hàm tính trung bình cộng các số nguyên tố trong ma trận số nguyên
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

int soNguyenTo(int a){
    if (a < 2) return 0;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return 0;
    }
    return 1;
}

float trungBinhSoNguyenTo(int** arr, int n, int m){
    int tong = 0;
    int dem = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(soNguyenTo(arr[i][j])){
                tong += arr[i][j];
                dem++;
            }
        }
    }
    if (dem == 0) {
    printf("\nKhông có số nguyên tố trong ma trận.");
    return 0;
    }
    return (float) tong / dem;
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
    
    float ketQua = trungBinhSoNguyenTo(arr, n, m);
    printf("\nTrung bình các số nguyên tố của ma trận là: %.2f", ketQua);

    for(int i = 0; i < n; i++){
        free(arr[i]);
        }
    free(arr);
    return 0;
}