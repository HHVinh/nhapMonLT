#include <stdio.h>

int main() 
{
    int n;                // Khai báo biến n
    double s = 0.0;      // Khởi tạo biến s là kiểu double để lưu tổng

    printf("Nhập số n: ");
    scanf("%d", &n);     // Nhập giá trị n từ bàn phím

    // Vòng lặp tính tổng từ 1/2 đến (2n + 1)/(2n + 2)
    for (int i = 1; i <= n; i++)
    {
        s = s + (2 * i - 1) / (double)(2 * i); // Cộng (2*i - 1)/(2*i) vào tổng s
    }

    // In ra kết quả
    printf("Kết quả là: %lf\n", s); // In kết quả với định dạng số thực (double)
    
    return 0; // Kết thúc chương trình
}
