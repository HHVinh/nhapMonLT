#include <stdio.h>
#include <math.h>  // Thư viện cần thiết cho toán tử căn bậc n

// Hàm tính căn bậc N của số x
double CanBacN(double x, int N) {
    // Kiểm tra điều kiện x âm, vì căn bậc chẵn của số âm không xác định trong số thực
    if (x < 0 && N % 2 == 0) {
        printf("Không thể tính căn bậc chẵn của số âm.\n");
        return -1;  // Trả về -1 nếu có lỗi
    }
    
    // Tính căn bậc N của x
    return pow(x, 1.0 / N);
}

int main() {
    double x;
    int N;
    
    // Nhập vào số x và bậc N
    printf("Nhập số x: ");
    scanf("%lf", &x);
    printf("Nhập bậc căn N: ");
    scanf("%d", &N);

    // Gọi hàm và in kết quả
    double result = CanBacN(x, N);
    if (result != -1) {
        printf("Căn bậc %d của %.2f là %.2f\n", N, x, result);
    }
    
    return 0;
}
