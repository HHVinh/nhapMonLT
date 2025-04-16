// Bài 398: Dịch phải xoay vòng theo chiều kim đồng hồ các giá trị nằm trên biên ma trận

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

/*int dichPhaiBienMaTran(int *arr, int n, int m){
    int tongSoPhanTuBien = (n + m) * 2 - 4;
    int k;
    printf("Nhập số cột cần xoay phải: ");
    scanf("%d", &k);

    if(k < 1){
        printf("Số lượng phần tử dịch phải không thể âm.\n");
        return 0;
    }

    // Đảm bảo k không lớn hơn tổng phần tử biên
    k = k % tongSoPhanTuBien;
    if(k == 0) return 1;  // Xoay k = 0 thì không cần làm gì

    int *temp = (int*) malloc(tongSoPhanTuBien * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }

    // Sao chép biên tarên
    int j = 0;
    for(int i = 0; i < m; i++){
        temp[j++] = arr[i];
    }

    // Sao chép biên phải
    for(int i = 0; i < n - 1; i++){
        temp[j++] = arr[(i + 1) * m - 1];
    }

    // Sao chép biên dưới
    for(int i = 0; i < m; i++){
        temp[j++] = arr[(n - 1) * m + i];
    }

    // Sao chép biên trái
    for(int i = 0; i < n - 1; i++){
        temp[j++] = arr[(i + 1) * m];
    }

    // Dịch phải k lần: A B C D E -> 2 lần -> D E A B C
    daoNguoc(temp, tongSoPhanTuBien - 1 - k, tongSoPhanTuBien - 1); // Đảo k phần tử cuối
    daoNguoc(temp, 0, tongSoPhanTuBien - 1 - k - 1); // Đảo số phần tử đầu còn lại
    daoNguoc(temp, 0, tongSoPhanTuBien - 1); // Đảo tất cả phần tử

    // Sao chép lại vào arr
    int l = 0;
    // Sao chép biên trên
    for(int i = 0; i < m; i++){
        arr[i] = temp[l++];
    }

    // Sao chép biên phải
    for(int i = 0; i < n - 1; i++){
        arr[(i + 1) * m - 1] = temp[l++];
    }

    // Sao chép biên dưới
    for(int i = 0; i < m; i++){
        arr[(n - 1) * m + i] = temp[l++];
    }

    // Sao chép biên trái
    for(int i = 0; i < n - 1; i++){
        arr[(i + 1) * m] = temp[l++];
    }

    free(temp);
    return 1;
}*/

int dichPhaiBienMaTran(int *arr, int n, int m) {
    int tongSoPhanTuBien = (n + m) * 2 - 4;
    int k;
    printf("Nhập số cột cần xoay phải: ");
    scanf("%d", &k);

    if(k < 1) {
        printf("Số lượng phần tử dịch phải không thể âm.\n");
        return 0;
    }

    // Đảm bảo k không lớn hơn tổng phần tử biên
    k = k % tongSoPhanTuBien;
    if(k == 0) return 1;  // Xoay k = 0 thì không cần làm gì

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
    if(n > 1) {
        for(int i = m - 1; i >= 0; i--) {
            temp[j++] = arr[(n - 1) * m + i];
        }
    }

    // Sao chép biên trái (bỏ góc trên và dưới)
    for(int i = n - 2; i >= 1; i--) {
        temp[j++] = arr[i * m];
    }

    // Dịch phải k lần
    daoNguoc(temp, 0, tongSoPhanTuBien - k - 1);
    daoNguoc(temp, tongSoPhanTuBien - k, tongSoPhanTuBien - 1);
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
    if(n > 1) {
        for(int i = m - 1; i >= 0; i--) {
            arr[(n - 1) * m + i] = temp[l++];
        }
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

    if(dichPhaiBienMaTran(arr, n, m)){
        printf("\nMa trận sau khi dịch phải biên là: \n");
        xuat(arr, n, m);
    }

    free(arr);
    return 0;
}
