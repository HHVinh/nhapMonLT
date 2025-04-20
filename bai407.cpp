// Bài 407: Viết hàm sắp xếp các phần tử trên 1 dòng tăng dần từ trái sang phải

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

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void sapXepDongTangDan(int *arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        qsort(arr + i * m, m, sizeof(int), compare); // Sắp xếp từng dòng
    }
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

    sapXepDongTangDan(arr,n,m);
    printf("\nMa trận vừa sắp xếp tăng dần là: \n");
    xuatMT(arr,n,m);

    free(arr);
    return 0;
    
}