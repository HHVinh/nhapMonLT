// Bài 359: Liệt kê các dòng có chứa giá trị âm trong ma trận các số thực
#include <stdio.h>
#include <stdlib.h>

void nhap(float *arr, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("Nhập phần tử A[%d][%d]: ", i / m, i % m);
        scanf("%f", &arr[i]);
    }
}

void xuat(float *arr, int n, int m) {
    printf("\nMa trận vừa nhập là:\n");
    for (int i = 0; i < n * m; i++) {
        printf("%8.2f", arr[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

void kiemTraDongAm(float *arr, int n, int m) {
    int coDongAm = 0;
    int *chiSoDong = (int*) calloc(n, sizeof(int));

    // Đánh dấu dòng có số âm
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i * m + j] < 0) {
                chiSoDong[i] = 1;
                coDongAm = 1;
                break;
            }
        }
    }

    // In ra các dòng đã đánh dấu
    if (coDongAm) {
        printf("\nCác dòng có chứa giá trị âm là:\n");
        for (int i = 0; i < n; i++) {
            if (chiSoDong[i]) {
                printf("Dòng %d: ", i);
                for (int j = 0; j < m; j++) {
                    printf("%8.2f", arr[i * m + j]);
                }
                printf("\n");
            }
        }
    } else {
        printf("\nKhông có dòng nào chứa giá trị âm.\n");
    }

    free(chiSoDong);
}

int main() {
    int n, m;
    printf("\nNhập hàng và cột: ");
    scanf("%d%d", &n, &m);

    float *arr = (float *)malloc(n * m * sizeof(float));
    if (arr == NULL) {
        printf("\nLỗi cấp phát bộ nhớ.");
        exit(1);
    }

    nhap(arr, n, m);
    xuat(arr, n, m);

    kiemTraDongAm(arr, n, m);

    free(arr);
    return 0;
}
