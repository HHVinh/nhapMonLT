#include <stdio.h>

int main() {
    int n, ketqua = 0;
    printf("Hãy nhập số bất kỳ: ");
    scanf("%d", &n);
    
    int danhSach[n]; // Khởi tạo mảng danhSach để lưu các ước số lẻ của n
    
    for (int i = 1; i <= n / 2; i++) {
        // Kiểm tra nếu i là ước của n và i là số lẻ
        if (n % i == 0 && i % 2 == 1) {
            danhSach[ketqua] = i;
            printf("Kết quả khi i = %d là: %d\n", i, danhSach[ketqua]);
            ketqua += 1; // Tăng sau khi đã in
        }
    }
    
    // Kiểm tra nếu n là số lẻ, thêm n vào danh sách vì n cũng là ước của chính nó
    if (n % 2 == 1) {
        danhSach[ketqua] = n;
        printf("Kết quả khi n là chính nó: %d\n", danhSach[ketqua]);
        // Không cần tăng ketqua ở đây nếu không thêm gì nữa
    }

    printf("Danh sách các ước số lẻ của %d là: ", n);
    for (int i = 0; i <= ketqua; i++) {
        printf("%d ", danhSach[i]);
    }
    return 0;
}

