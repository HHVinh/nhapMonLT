#include <stdio.h>
#include <stdlib.h>

void nhapMang(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i/m, i%m);
        scanf("%d", &arr[i]);
    }
}

void xuatMang(int *arr, int n, int m){
    for (int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0){
            printf("\n");
        }
    }
}

int main(){
    int n, m;
    printf("Nhập số lượng dòng và cột:");
    scanf("%d%d", &n,&m);

    int *arr = (int*) malloc(n*m * sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát bộ nhớ"); exit(1);
    }

    nhapMang(arr, n, m);
    printf("\nMa trận vừa nhập là: \n");
    xuatMang(arr, n, m);

    free(arr);
    return 0;
}