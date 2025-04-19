// Bài 400: Xóa 1 cột trong ma trận

#include <stdio.h>
#include <stdlib.h>

void nhapMT(int *arr, int n, int m){
    for(int i = 0; i< n*m; i++){
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

void xuatMT(int *arr, int n, int m){
    for(int i = 0; i < n*m; i++){
        printf("%5d", arr[i]);
        if((i+1) % m == 0){
            printf("\n");
        }
    }
}

int* xoaCotConTroCap1(int *arr, int n, int *m){
    int k;
    printf("Nhập cột cần xóa từ 0 đến %d: ", *m-1);
    scanf("%d", &k);
    if(k < 0 || k > *m - 1){
        do{
            printf("Bạn đã nhập sai. Nhập lại cột cần xóa từ 0 đến %d: ", *m-1);
            scanf("%d",&k);
        } while(k < 0 || k > *m - 1);
    }

    int *temp = (int*) malloc( n * (*m-1) * sizeof(int));
    if(temp == NULL){
        printf("Lỗi cấp phát."); exit(1);
    }

    int phanTuTemp = 0;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < *m; j++){
            if(j != k){
                temp[phanTuTemp++] = arr[i * (*m) +j];
            }
        }
    }

    free(arr);
    (*m)--;
    return temp;
}

int* xoaCotConTroCap1Cach1VongFor(int *arr, int n, int *m) {
    int k;
    printf("Nhập cột cần xóa từ 0 đến %d: ", *m - 1);
    scanf("%d", &k);
    if(k < 0 || k > *m - 1) {
        do {
            printf("Bạn đã nhập sai. Nhập lại cột cần xóa từ 0 đến %d: ", *m - 1);
            scanf("%d", &k);
        } while(k < 0 || k > *m - 1);
    }

    int *temp = (int*) malloc(n * (*m - 1) * sizeof(int));
    if(temp == NULL) {
        printf("Lỗi cấp phát."); exit(1);
    }

    int new_cols = *m - 1; // Số cột mới
    for (int i = 0, j = 0; i < n * (*m); i++) {
        int current_col = i % (*m); // Cột hiện tại
        if (current_col != k) {     // Nếu không phải cột cần xóa
            temp[j++] = arr[i];    // Copy vào mảng mới
        }
    }

    free(arr);
    (*m)--; // Giảm số cột
    return temp;
}

int main(){

    int n, m;
    printf("Nhập số dòng - cột của ma trận: "); scanf("%d%d", &n,&m);

    int *arr = (int*) malloc(n * m *sizeof(int));
    if(arr == NULL){
        printf("Lỗi cấp phát."); exit(1);
    }

    nhapMT(arr,n,m);
    printf("\nMa trận vừa nhập là: \n");
    xuatMT(arr,n,m);

    arr = xoaCotConTroCap1(arr,n,&m);
    printf("\nMa trận vừa xóa cột là: \n");
    xuatMT(arr,n,m);

    free(arr);
    return 0;
    
}