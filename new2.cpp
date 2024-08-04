#include <iostream>

int main() {
    // Khai báo các biến để lưu trữ số nhập vào
    int num1, num2;

    // Nhập hai số từ người dùng
    std::cout << "Nhập số thứ nhất: ";
    std::cin >> num1;

    std::cout << "Nhập số thứ hai: ";
    std::cin >> num2;

    // So sánh hai số và in kết quả
    if (num1 > num2) {
        std::cout << "Số lớn hơn là: " << num1 << std::endl;
    } else if (num2 > num1) {
        std::cout << "Số lớn hơn là: " << num2 << std::endl;
    } else {
        std::cout << "Hai số bằng nhau." << std::endl;
    }

    return 0;
}
