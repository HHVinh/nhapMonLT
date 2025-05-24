// Bài 401: Xóa 1 cột trong ma trận
#include <stdio.h>
#include <stdlib.h>

void xoaCot(int** arr, int n, int *m){
    int k; printf("Nhập vị trí cột cần xóa (0 đến %d): ", *m - 1); scanf("%d", &k);
    if (k < 0 || k >= *m) {
        printf("Vị trí không hợp lệ!\n"); exit(1);
    }
    for(int i = 0; i < n; i++){
        int* temp = (int*) malloc((*m - 1) * sizeof(int));
        if(temp == NULL){
            printf("Lỗi"); exit(1);
        }

        for(int j = 0; j < k; j++){
            temp[j] = arr[i][j];
        }
        for(int j = k + 1; j < *m; j++){
            temp[j - 1] = arr[i][j];
        }

        free(arr[i]);
        arr[i] = temp;
    }

    *m -= 1;
}

void xoaCot2(int*** arr, int n, int* m) {
    int k;
    printf("Nhập vị trí cột cần xóa (0 đến %d): ", *m - 1);
    scanf("%d", &k);

    if (k < 0 || k >= *m) {
        printf("Vị trí không hợp lệ!\n");
        return;
    }

    int** temp = (int**) malloc(n * sizeof(int*));
    if (temp == NULL) {
        printf("Lỗi cấp phát!");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        temp[i] = (int*) malloc((*m - 1) * sizeof(int));
        if (temp[i] == NULL) {
            printf("Lỗi cấp phát!");
            for (int j = 0; j < i; j++) free(temp[j]);
            free(temp);
            exit(1);
        }

        int col = 0;
        for (int j = 0; j < *m; j++) {
            if (j == k) continue;
            temp[i][col++] = (*arr)[i][j];
        }
    }

    // Giải phóng ma trận cũ
    for (int i = 0; i < n; i++) {
        free((*arr)[i]);
    }
    free(*arr);

    // Gán lại con trỏ và số cột
    *arr = temp;
    (*m)--;
    if(*m == 0){
        printf("\nBạn đã xóa cột duy nhất trong ma trận!");
    } else {
        printf("\nMa trận sau khi xóa cột %d là:\n", k);
    }
}

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
        // Giải phóng các cột đã cấp phát trước đó
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
    
    xoaCot(arr, n, &m);
    xuatMang(arr, n, m);

 
    for(int i = 0; i < n; i++){
        free(arr[i]);
        }
    free(arr);
    return 0;
}