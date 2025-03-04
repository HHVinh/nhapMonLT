#include <stdio.h>
#include <stdlib.h>

void nhapMang(int ** pn, int *n){

    printf("Nhập số lượng phần tử: ");
    scanf("%d",n);
    *pn = (int*) malloc(*n * sizeof(int));
    if (*pn == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    // Nhập mảng
    for(int i = 0; i < *n; i++){
        printf("Nhập phần tử thứ %d của mảng: ", i+1);
        scanf("%d", &(*pn)[i]); // Hoặc (*pn) + i hoặc &pn[0][i], pn[0] chính là *pn
    }
}

void xuatMang(int *pn, int n){
    // Xuất mảng
    for(int i = 0; i < n; i++){
        printf("Phần tử %d của mảng: %d\n", i+1, pn[i]);
    }
}

void xoaPhanTuChan(int **pa, int *n){
    int count = 0;
    for(int i = 0; i < *n; i++){
        if((*pa)[i] % 2 != 0){
            count++;
        }
    }

    int *pb = (int*) malloc(count * sizeof(int));
    if (pb == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    int j = 0;
    for(int i = 0; i < *n; i++){
        if((*pa)[i] % 2 != 0){
            pb[j] = (*pa)[i];
            j++;
        }
    }
    free(*pa);
    *pa = pb;
    (*n) = count;
}

int main(){

    int *pn, n;
    nhapMang(&pn, &n);
    xoaPhanTuChan(&pn, &n);
    xuatMang(pn, n);

    free(pn);
    return 0;
}
