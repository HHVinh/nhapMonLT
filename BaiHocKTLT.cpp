#include <stdio.h>
#include <stdlib.h>

void nhapMang(int ** pn, int *n){

    printf("Nhập số lượng phần tử: ");
    scanf("%d",n);
    *pn = (int*) malloc(*n * sizeof(int));
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

    // int a = 3, b = 6;
    // int arr1[3] = {10,20,30};
    // int arr2[3] = {40,50,60}; 
    // int *pa = &a; int *pb = &b;
    // // *parr1 và *parr2 là con trỏ của arr1 và arr2
    // int *parr1 = arr1;  // Mà arr1 là hằng con trỏ của arr1[0] nên không cần & khi gán bên dưới
    // int *parr2 = &arr2[0]; // Vì arr2[0] là giá trị nên mới cần dùng &

    // printf(" Giá trị của a = %d", a);
    // printf("\n Địa chỉ a (&a) = %p", &a);
    // printf("\n Giá trị của pa cũng chính là địa chỉ của a (&a) = %p", pa);
    // printf("\n *pa là giá trị vùng nhớ pa đang trỏ tới (a) = %d", *pa);
    // printf("\n Địa chỉ của pa (&pa) = %p", &pa);
    
    // int *x = &a, *y = &b, t = 0;
    // printf("\nx = %d",*x);
    // printf("\ny = %d",*y);
    // printf("\nt = %d",t);
    // printf("\nSau khi hoán vị:");
    // t = *x; *x = *y; *y = t;
    // printf("\nx = %d",*x);
    // printf("\ny = %d",*y);
    // printf("\nt = %d",t);

    // printf("\n Địa chỉ parr1 = %p", parr1);
    // printf("\n Địa chỉ parr2 = %p", parr2);
    // printf("\n Giá trị parr1 = %d", *parr1);
    // printf("\n Giá trị parr2 = %d", *parr2);
    // printf("\nGiá trị của arr1[2] = parr1[2] = *(parr1 + 2)");
    // printf("\n %d - %d - %d", arr1[2], parr1[2], *(parr1+2));
    // int phepTru1 = parr1 - parr2;
    // int phepTru2 = parr2 - parr1;
    // printf("\n %d", phepTru1);
    // printf("\n %d", phepTru2);

void chenPhanTU(int ** pa, int *n, int k, int value){
    int *pb = (int*) malloc(*n+1 * sizeof(int));
    for(int i = 0; i < k; i++){
        pb[i] = (*pa)[i];
    }
    pb[k] = value;
    for(int i = k; i < *n; i++){
        pb[i + 1] = (*pa)[i];
    }
    (*n)++;
    free(*pa);
    *pa = pb;
}    

void xoaPhanTu(int ** pa, int *n, int k){

    int *pb = (int *)malloc((*n-1)* sizeof(int));
    for(int i = 0; i < k-1; i++){
        pb[i] = (*pa)[i];
    }
    for(int i = k; i < *n; i++){
        pb[i-1] = (*pa)[i];
    }
    (*n)--;
    free(*pa);
    *pa = pb;
}

int main(){
    
    int *pn, n;
    int k = 2, value = 9;
    nhapMang(&pn, &n);
    xoaPhanTu(&pn, &n, k);
    xuatMang(pn, n);
    free(pn); // Giải phóng bộ nhớ

    return 0;
}