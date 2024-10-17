// math_functions.c
#include <stdio.h>
#include <math.h>
#include "khaiBaoHam.h"

int tongTu1DenN(int n) {
    return n * (n + 1) / 2;  // Công thức tính tổng 1 + 2 + ... + n
}

int tinhXMu2(int x) {
    return x * x;  // Tính x mũ 2
}

double tinhCanBac2(double x) {
    return (x >= 0) ? sqrt(x) : -1;  // Tính căn bậc 2
}
