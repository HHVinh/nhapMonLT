#include <iostream>

bool isValidTriangle(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    int a, b, c;

    // Nhập ba cạnh từ người dùng
    std::cout << "Nhập cạnh a: ";
    std::cin >> a;

    std::cout << "Nhập cạnh b: ";
    std::cin >> b;

    std::cout << "Nhập cạnh c: ";
    std::cin >> c;

    // Kiểm tra và in kết quả
    if (isValidTriangle(a, b, c)) {
        std::cout << "Ba cạnh tạo thành một tam giác hợp lệ." << std::endl;
    } else {
        std::cout << "Ba cạnh không tạo thành một tam giác hợp lệ." << std::endl;
    }

    return 0;
}
