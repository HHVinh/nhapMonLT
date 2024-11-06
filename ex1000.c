#include <stdio.h>

int main() {
    int n;
    int dem = 0; // Biến đếm số lượng ước số

    printf("Hay nhap so nguyen bat ki: ");
    scanf("%d", &n);
    int uocChung[n]; // Mảng lưu trữ các ước số
    
    // Tìm các ước số của n
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) { // Kiểm tra nếu i là ước số của n
            uocChung[dem] = i; // Lưu ước số vào mảng
            dem++; // Tăng biến đếm
        }
    }
    uocChung[dem] = n; // Thêm chính số n vào danh sách ước số
    dem++; // Tăng biến đếm

    // In ra các ước số
    printf("Cac uoc so cua %d la: ", n);
    for (int i = 0; i < dem; i++) {
        printf("%d ", uocChung[i]); // In ra từng ước số
    }
    printf("\n"); // Xuống dòng sau khi in xong

    return 0;
}
