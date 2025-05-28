// Câu 2 Cho một ma trận gồm các số nguyên, viết hàm chèn vào 1 dòng vào sau dòng k. chen(mang2chieu, mang1chieumuonchen, k)
#include <stdio.h>
#include <stdlib.h>

void chen1DongSauDongK(int*** arr, int* n, int m, int k) {
    if (k >= *n) {
    printf("Vị trí dòng k không hợp lệ.\n");
    return;
    }
    // Cấp phát dòng mới
    int* dongMuonChen = (int*)malloc(m * sizeof(int));
    if (dongMuonChen == NULL) {
        printf("Lỗi cấp phát bộ nhớ cho dòng mới!\n");
        exit(1);
    }

    printf("Nhập %d giá trị cho dòng muốn chèn:\n", m);
    for (int i = 0; i < m; i++) {
        printf("Giá trị [%d]: ", i);
        scanf("%d", &dongMuonChen[i]);
    }

    // Tạo mảng con trỏ mới (n + 1 dòng)
    int** temp = (int**)malloc((*n + 1) * sizeof(int*));
    if (temp == NULL) {
        printf("Lỗi cấp phát mảng 2 chiều mới!\n");
        exit(1);
    }

    // Sao chép các dòng trước dòng k+1
    for (int i = 0; i <= k && i < *n; i++) {
        temp[i] = (*arr)[i];
    }

    // Chèn dòng mới vào sau dòng k
    temp[k + 1] = dongMuonChen;

    // Sao chép phần còn lại
    for (int i = k + 1; i < *n; i++) {
        temp[i + 1] = (*arr)[i];
    }

    // Giải phóng mảng cũ (không giải phóng từng dòng vì ta giữ nguyên địa chỉ)
    free(*arr);

    // Gán lại con trỏ và cập nhật số dòng
    *arr = temp;
    (*n)++;
}

void nhapMaTran(int **arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j ++){
            printf("Nhập phần tử A[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void xuatMaTran(int **arr, int n, int m){
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            printf("%5d", arr[i][j]);
        }
        printf("\n");
    }
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

    nhapMaTran(arr, n, m);

    printf("\nMa trận vừa nhập là: \n");
    xuatMaTran(arr, n, m);
  
    chen1DongSauDongK(&arr, &n, m, 1);
    printf("\nMa trận vừa chèn thêm là: \n");
    xuatMaTran(arr, n, m);
    
    for(int i = 0; i < n; i++){
        free(arr[i]);
        }
    free(arr);
    return 0;
}