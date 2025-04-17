// Bài 399: Dịch trái xoay vòng theo chiều kim đồng hồ các giá trị nằm trên biên ma trận

#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuat(int *arr, int n, int m){
    for(int i = 0; i < n * m; i++){
        printf("%5d", arr[i]);
        if((i + 1) % m == 0){
            printf("\n");
        }
    }
}

void daoNguoc(int *arr, int left, int right){
    while (left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}


int dichTraiBienMaTran(int *arr, int n, int m) {
    int tongSoPhanTuBien = (n == 1 || m == 1) ? n * m : (n + m) * 2 - 4;
    int k;
    printf("Nhập số lần dịch trái: ");
    scanf("%d", &k);

    if(k < 1) {
        printf("Số lượng phần tử dịch trái không thể âm.\n");
        return 0;
    }

    // Xử lý ma trận 1D, k = 2.  A B C D E -> B A C D E -> B A E D C -> C D E A B
    if(n == 1 || m == 1) {
        daoNguoc(arr, 0, k - 1);
        daoNguoc(arr, k, tongSoPhanTuBien - 1);
        daoNguoc(arr, 0, tongSoPhanTuBien - 1);
        return 1;
    }

    // Xử lý ma trận 2D
    int *temp = (int*) malloc(tongSoPhanTuBien * sizeof(int));
    if(temp == NULL) {
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    // Sao chép biên trên
    int j = 0;
    for(int i = 0; i < m; i++) {
        temp[j++] = arr[i];
    }

    // Sao chép biên phải (bỏ góc trên và dưới đã sao chép)
    for(int i = 1; i < n - 1; i++) {
        temp[j++] = arr[i * m + m - 1];
    }

    // Sao chép biên dưới (theo thứ tự từ phải sang trái)
    for(int i = m - 1; i >= 0; i--) {
        temp[j++] = arr[(n - 1) * m + i];
    }

    // Sao chép biên trái (bỏ góc trên và dưới)
    for(int i = n - 2; i >= 1; i--) {
        temp[j++] = arr[i * m];
    }

    // dịch trái k lần
    daoNguoc(temp, 0, k - 1);
    daoNguoc(temp, k, tongSoPhanTuBien - 1);
    daoNguoc(temp, 0, tongSoPhanTuBien - 1);

    // Sao chép lại vào arr
    int l = 0;
    // Sao chép biên trên
    for(int i = 0; i < m; i++) {
        arr[i] = temp[l++];
    }

    // Sao chép biên phải
    for(int i = 1; i < n - 1; i++) {
        arr[i * m + m - 1] = temp[l++];
    }

    // Sao chép biên dưới
    for(int i = m - 1; i >= 0; i--) {
        arr[(n - 1) * m + i] = temp[l++];
    }

    // Sao chép biên trái
    for(int i = n - 2; i >= 1; i--) {
        arr[i * m] = temp[l++];
    }

    free(temp);
    return 1;
}

int main(){
    int n, m;
    printf("Nhập số lượng dòng và cột: ");
    scanf("%d%d", &n, &m);

    int *arr = (int*) malloc(n * m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    nhap(arr, n, m);
    printf("\nMa trận vừa nhập là: \n");
    xuat(arr, n, m);

    if(dichTraiBienMaTran(arr, n, m)){
        printf("\nMa trận sau khi dịch trái biên là: \n");
        xuat(arr, n, m);
    }

    free(arr);
    return 0;
}