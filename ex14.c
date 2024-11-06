#include <stdio.h>

int main() {
    int x, n, ketQua = 0;
    printf("Hay nhap hai so nguyen bat ki (x va n): ");
    scanf("%d %d", &x, &n);
    
    int luyThua = x; // Bắt đầu từ luy thừa x^1
    for (int i = 1; i <= n; i++) {
        ketQua += luyThua; // Cộng lũy thừa hiện tại vào tổng
        printf("Ket qua khi i = %d la: %d\n", i, ketQua); // In kết quả ở mỗi bước
        luyThua *= x * x; // Nhân với x^2 để đạt lũy thừa lẻ tiếp theo
    }
    
    printf("Ket qua la: %d\n", ketQua); // In kết quả cuối cùng
    return 0;
}
