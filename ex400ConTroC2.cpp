// Bài 400: Xóa 1 dòng trong ma trận
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

void xoaDong(int*** arr, int* n, int m) {
    int k;
    printf("Nhập vị trí dòng cần xóa (0 đến %d): ", *n - 1);
    scanf("%d", &k);

    if (k < 0 || k >= *n) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }

    // Giải phóng dòng cần xóa
    free((*arr)[k]);

    // Dời các dòng sau lên
    for (int i = k; i < *n - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }

    // Không cần free arr[*n - 1] vì bạn đã giải phóng dòng cần xóa rồi
    (*n)--;
    if(*n == 0){
        printf("\nBạn đã xóa dòng duy nhất trong ma trận!");
    } else {
        printf("\nMa trận sau khi xóa dòng %d là:\n", k);
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

    nhapMang(arr, n, m);
    printf("\nMa trận vừa nhập là: \n");
    xuatMang(arr, n, m);
    
    xoaDong(&arr, &n, m);
    xuatMang(arr, n, m);

 
    for(int i = 0; i < n; i++){
        free(arr[i]);
        }
    free(arr);
    return 0;
}