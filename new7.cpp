#include <iostream>

int main()
{
    
    int a, b, c, max;
    std::cout << "Nhập 3 số nguyên: ";
    std::cin >> a >> b >> c;

    max = a;
    if (b > max)
        max = b;
    if (c > max)
        max = c;

    std::cout << "Số lớn nhất là: " << max << std::endl;

    return 0;
}
