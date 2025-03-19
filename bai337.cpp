#include <stdio.h>
#include <stdlib.h>
#include <math.h>  // Thêm thư viện math.h để dùng log10

void nhap(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

int demSoChuSo(int *arr, int n, int m){
    int dem = 0;
    for(int i = 0; i < n * m; i++){
        int temp = arr[i];  // Giữ giá trị gốc
        while(temp > 0){
            temp /= 10;
            dem++;
        }
    }
    return dem;
}

// Hàm log10(x) trong C dùng để tính logarithm cơ số 10 của số x
// Ví dụ log10(500) = 2.7
// 2.7 + 1 = 3.7 
// => (int)3.7 = 3 số
int demSoChuSoCach2(int *arr, int n, int m){
    int dem = 0;
    for(int i = 0; i < n * m; i++){
        if (arr[i] > 0) {
            dem += (int)log10(arr[i]) + 1;  
        }
    }
    return dem;
}


int main() {
    int n, m;
    printf("\nNhập số lượng dòng và cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    int ketQua = demSoChuSo(arr, n, m);
    printf("\nTổng số chữ số của ma trận là: %d\n", ketQua);
    int ketQua2 = demSoChuSoCach2(arr, n, m);
    printf("\nTổng số chữ số của ma trận là: %d\n", ketQua);

    free(arr);
    return 0;
}
