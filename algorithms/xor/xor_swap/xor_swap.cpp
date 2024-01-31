#include <iostream>
#include <cstring>

void xorSwap(int &a, int &b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

int main() {
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;

    xorSwap(a, b);

    std::cout << "After swap a = " << a << " b = " << b << std::endl;

    return 0;
}