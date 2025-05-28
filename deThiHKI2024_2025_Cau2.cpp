// Câu 2: Xóa dòng thứ k trên ma trận số nguyên có kích thước n x m 
#include <stdio.h>
#include <stdlib.h>
void xoa1DongViTriK(int*** arr, int* n, int m, int k) {
    if (k < 0 || k >= *n) {
        printf("Vị trí dòng k không hợp lệ.\n");
        return;
    }

    // Giải phóng dòng cần xóa
    free((*arr)[k]);

    // Dời các dòng phía sau lên
    for (int i = k; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    // Cập nhật số dòng
    (*n)--;

    // Thu nhỏ mảng con trỏ dòng lại
    int** temp = (int**) realloc(*arr, (*n) * sizeof(int*));
    if (temp == NULL && *n > 0) {
        printf("Lỗi khi thu nhỏ mảng dòng.\n");
        exit(1);
    }
    *arr = temp;
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
    
    xoa1DongViTriK(&arr, &n, m, 1);
    printf("\nMa trận vừa xóa dòng là: \n");
    xuatMaTran(arr, n, m);
    
    for(int i = 0; i < n; i++){
        free(arr[i]);
        }
    free(arr);
    return 0;
}