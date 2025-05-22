#include <stdio.h>
#include <stdlib.h>

void nhapMang(float** arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Nhập phần tử A[%d][%d]: ", i, j);
            scanf("%f", &arr[i][j]);
        }
    }
}

void xuatMang(float** arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%5.2f", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n, m;
    printf("Nhập số lượng dòng và cột: ");
    scanf("%d%d", &n, &m);

    float** arr = (float**) malloc(n * sizeof(float*));
    if(arr == NULL){
        printf("Lỗi");
        return 1;
    }

    for(int i = 0; i < n; i++){
        arr[i] = (float*) malloc(m * sizeof(float));
        if(arr[i] == NULL){
        printf("Lỗi");
        for(int j = 0; j < n; j++){
            free(arr[j]);
        }
        free(arr);
        return 1;
        }
    }

    nhapMang(arr, n, m);
    printf("\n");
    xuatMang(arr, n, m);

    for(int i = 0; i < n; i++){
        free(arr[i]);
    }
    free(arr);
    return 0;
}