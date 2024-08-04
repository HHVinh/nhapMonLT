#include <iostream>

int main() {
    int number = 1; // Khởi tạo số bắt đầu từ 1

    for (int i = 1; i <= 9; ++i) { // Duyệt qua từng hàng
        for (int j = 1; j <= i; ++j) { // In các số trên từng hàng
            std::cout << number << " ";
            ++number; // Tăng số tiếp theo
        }
        std::cout << std::endl; // Xuống dòng sau khi in hết một hàng
    }

    return 0;
}
