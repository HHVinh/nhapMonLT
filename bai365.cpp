// Bài 365: Cho 2 ma trận A và B. Đếm số lần xuất hiện của ma trận A trong ma trận B
#include <stdio.h>
#include <stdlib.h>

// Nhập ma trận
void nhap(int *a, int n, int m, char ten) {
    printf("\nNhập ma trận %c (%dx%d):\n", ten, n, m);
    for (int i = 0; i < n * m; i++) {
        printf("%c[%d][%d] = ", ten, i / m, i % m);
        scanf("%d", &a[i]);
    }
}

// Xuất ma trận
void xuat(int *a, int n, int m) {
    for (int i = 0; i < n * m; i++) {
        printf("%5d", a[i]);
        if ((i + 1) % m == 0) printf("\n");
    }
}

// Hàm đếm số lần A xuất hiện trong B
int demSoLanXuatHien(int *a, int *b, int nA, int mA, int nB, int mB) {
    int count = 0;

    for (int i = 0; i <= nB - nA; i++) {
        for (int j = 0; j <= mB - mA; j++) {
            int khop = 1;
            for (int x = 0; x < nA && khop; x++) {
                for (int y = 0; y < mA; y++) {
                    if (a[x * mA + y] != b[(i + x) * mB + (j + y)]) {
                        khop = 0;
                        break;
                    }
                }
            }
            if (khop) count++;
        }
    }

    return count;
}

int main() {
    int nA, mA, nB, mB;
    char tenA = 'A', tenB = 'B';

    printf("Nhập số dòng và cột của ma trận A: ");
    scanf("%d%d", &nA, &mA);
    int *a = (int *)malloc(nA * mA * sizeof(int));
    nhap(a, nA, mA, tenA);

    printf("Nhập số dòng và cột của ma trận B: ");
    scanf("%d%d", &nB, &mB);
    int *b = (int *)malloc(nB * mB * sizeof(int));
    nhap(b, nB, mB, tenB);

    printf("\nMa trận A:\n");
    xuat(a, nA, mA);
    printf("\nMa trận B:\n");
    xuat(b, nB, mB);

    int soLan = demSoLanXuatHien(a, b, nA, mA, nB, mB);
    printf("\nMa trận A xuất hiện %d lần trong ma trận B.\n", soLan);

    free(a);
    free(b);
    return 0;
}
