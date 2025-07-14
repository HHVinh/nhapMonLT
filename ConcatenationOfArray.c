#include <stdio.h>

int main() {
    int nums[1000];     // Mảng gốc (tối đa 1000 phần tử)
    int ans[2000];      // Mảng kết quả (gấp đôi kích thước)
    int n;

    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (1-1000): ");
    scanf("%d", &n);

    if (n < 1 || n > 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }

    // Nhập các phần tử mảng
    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Tạo mảng ans bằng cách ghép 2 lần nums
    for (int i = 0; i < n; i++) {
        ans[i] = nums[i];
        ans[i + n] = nums[i];
    }

    // In kết quả
    printf("Mang ket qua: ");
    for (int i = 0; i < 2 * n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}
