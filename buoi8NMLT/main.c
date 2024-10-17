// main.c
#include <stdio.h>
#include <math.h>
#include "khaiBaoHam.h"

int main() {
    int n = 5;
    int x = 3;
    double y = 16.0;

    printf("Tổng từ 1 đến %d là: %d\n", n, tongTu1DenN(n));
    printf("%d mũ 2 là: %d\n", x, tinhXMu2(x));
    printf("Căn bậc 2 của %.2f là: %.2f\n", y, tinhCanBac2(y));

    return 0;
}
