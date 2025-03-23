// Bài 361: Liệt kê các dòng trong ma trận các số thực thỏa mãn đồng thời các điều kiện sau:
// dòng có chứa giá trị âm, giá trị 0 và giá trị dương
#include <stdio.h>
#include <stdlib.h>

void nhap(float *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%f", &arr[i]);
    }
}

void xuat(float *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%8.2f", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

void kiemTraDongThoaDieuKien(float *arr, int n, int m) {
    int thoaDieuKien = 0;
    int *chiSoDong = (int*) calloc(n, sizeof(int));
    if(m < 3){
        printf("\nÍt nhất phải có 3 cột.");
        return;
    }
    // Đánh dấu dòng đúng điều kiện
    for (int i = 0; i < n; i++) {
        int soAm = 0, so0 = 0, soDuong = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i * m + j] < 0) soAm = 1;
            else if (arr[i * m + j] == 0) so0 = 1;
            else if (arr[i * m + j] > 0) soDuong = 1;
        }
        if(soAm && so0 && soDuong){
            thoaDieuKien = 1;
            chiSoDong[i] = 1;
        }
    }
    if(thoaDieuKien){
        printf("\nDòng thỏa điều kiện là: \n");
        for(int i = 0; i < n; i++){
            if(chiSoDong[i]){
                printf("Dòng %d: ", i);
                for(int j = 0; j < m; j++){
                    printf("%8.2f", arr[i * m + j]);
                }
                printf("\n");
            }
        }
    } else{
        printf("\nKhông có dòng nào thỏa điều kiện.");
    }
    free(chiSoDong);
}

int main() {
    int n, m;
    printf("\nNhập hàng và cột: ");
    scanf("%d%d", &n, &m);

    float *arr = (float *)malloc(n * m * sizeof(float));
    if (arr == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    kiemTraDongThoaDieuKien(arr, n, m);

    free(arr);
    return 0;
}
