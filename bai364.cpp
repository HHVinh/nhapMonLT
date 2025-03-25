// Bài 364: Cho 2 ma trận A và B. Kiểm tra xem ma trận A có là ma trận con của ma trận B hay không
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Hàm nhập ma trận
void nhap(int *arr, char ten, int n, int m) {
    printf("\nNhập ma trận %c(%dx%d): \n", ten, n, m);
    for (int i = 0; i < n * m; i++) {
        printf("Nhập A[%d][%d]: ", i / m, i % m);
        scanf("%d", &arr[i]);
    }
}

// Hàm xuất ma trận
void xuat(int *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("%5d", arr[i]);
        if ((i + 1) % m == 0) {
            printf("\n");
        }
    }
}

int kiemTraMaTranCon(int *arrA, int *arrB, int nA, int mA, int nB, int mB){
    if(nB < nA || mB < mA){
        return 0;
    }
    for (int i = 0; i <= nB - nA; i++) {
        for (int j = 0; j <= mB - mA; j++) {
            int khop = 1;
            for (int x = 0; x < nA; x++) {
                for (int y = 0; y < mA; y++) {
                    int giaTriA = arrA[x * mA + y];
                    int giaTriB = arrB[(i + x) * mB + (j + y)];
                    if (giaTriA != giaTriB) {
                        khop = 0;
                        break;
                    }
                }
                if (!khop) break;
            }
            if (khop) return 1;
        }
    }
    return 0;
}

int main() {
    int nA, mA;
    int nB, mB;
    char tenA, tenB;
    
    printf("\nNhập tên, hàng và cột ma trận 1: ");
    scanf(" %c%d%d", &tenA, &nA, &mA);

    int *arrA = (int *)malloc(nA * mA * sizeof(int));
    if (arrA == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arrA, tenA, nA, mA);

    printf("\nNhập tên, hàng và cột ma trận 2: ");
    scanf(" %c%d%d", &tenB, &nB, &mB);

    int *arrB = (int *)malloc(nB * mB * sizeof(int));
    if (arrB == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arrB, tenB, nB, mB);

    printf("\nMa trận %c vừa nhập là:\n", tenA);
    xuat(arrA, nA, mA);

    printf("\nMa trận %c vừa nhập là:\n", tenB);
    xuat(arrB, nB, mB);

    if(kiemTraMaTranCon(arrA, arrB, nA, mA, nB, mB)){
        printf("\nMa trận %c là con ma trận %c.", tenA, tenB);
    } else{
        printf("\nMa trận %c không là con ma trận %c.", tenA, tenB);
    }

    free(arrA);
    free(arrB);
    return 0;
}
