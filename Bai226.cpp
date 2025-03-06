#include <stdio.h>
#include <stdlib.h>
// Bài 266: Thêm 1 phần tử x vào mảng tại vị trí k

void nhapMang(int **p2, int *n){
    *p2 = (int*) malloc((*n+1) * sizeof(int));
    if( *p2 ==  NULL){
        printf("\n Lỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    for(int i = 0; i < *n; i++){
        printf("Nhập phần tử thứ %d: ", i+1);
        scanf("%d", &(*p2)[i]);
    }
}

void xuatMang(int *p1, int n){
    printf("\nMảng vừa nhập là: ");
    for(int i = 0; i < n; i++){
        printf("%3d", p1[i]);
    }
}

void themPhanTu(int **p2, int *n, int k, int value){
    int *p1 = (int*) malloc ((*n+1) * sizeof(int));
    if( p1 == NULL){
        printf("\nLỗi cấp phát bộ nhớ.\n");
        exit(1);
    }
    for(int i = 0; i < k; i++){
        p1[i] = (*p2)[i];
    }
    p1[k] = value;
    for(int i = k; i < *n; i++){
        p1[i+1] = (*p2)[i];
    }

    free(*p2);
    *p2 = p1;
    (*n)++;
}

int main(){

    int n; printf("Nhập n: "); scanf("%d", &n);
    int *p1 = NULL;
    nhapMang(&p1, &n);
    xuatMang(p1, n);

    int k, value;
    printf("\nNhập k từ 0 - %d: ", n-1); scanf("%d", &k);
    printf("Nhập value: "); scanf("%d", &value);

    themPhanTu(&p1, &n, k, value);
    printf("\nMảng sau khi thêm là: ");
    xuatMang(p1, n);

    free(p1);
    return 0;
}