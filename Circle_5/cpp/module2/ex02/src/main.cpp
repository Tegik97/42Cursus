#include <iostream>
#include "Fixed.hpp"

int main(void)
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
	Fixed c(b);

    std::cout << "=== Test incremento/decremento ===" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "c--: " << c-- << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "--c: " << --c << std::endl;

    std::cout << "\n=== Test operatori aritmetici ===" << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "a * b: " << a * b << std::endl;
	std::cout << "a / b: " << a / b << std::endl;

    std::cout << "\n=== Test operatori di confronto ===" << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "\n=== Test min/max ===" << std::endl;
	std::cout << "Fixed::min(b, c): " << Fixed::min(b, c) << std::endl;
    std::cout << "Fixed::max(a, b): " << Fixed::max(a, b) << std::endl;

    std::cout << "\n=== Test min/max con const ===" << std::endl;
    const Fixed const1(3.5f);
    const Fixed const2(7.2f);
    Fixed nonConst1(1.1f);
    Fixed nonConst2(9.9f);
    
    std::cout << "const1: " << const1 << std::endl;
    std::cout << "const2: " << const2 << std::endl;
    std::cout << "nonConst1: " << nonConst1 << std::endl;
    std::cout << "nonConst2: " << nonConst2 << std::endl;
    
    // Test versione const di min/max
    std::cout << "Fixed::min(const1, const2): " << Fixed::min(const1, const2) << std::endl;
    std::cout << "Fixed::max(const1, const2): " << Fixed::max(const1, const2) << std::endl;
    
    // Test versione non-const di min/max
    std::cout << "Fixed::min(nonConst1, nonConst2): " << Fixed::min(nonConst1, nonConst2) << std::endl;
    std::cout << "Fixed::max(nonConst1, nonConst2): " << Fixed::max(nonConst1, nonConst2) << std::endl;
    
    // Test misto (dovrebbe scegliere versione const)
    std::cout << "Fixed::min(const1, nonConst1): " << Fixed::min(const1, nonConst1) << std::endl;
    std::cout << "Fixed::max(const2, nonConst2): " << Fixed::max(const2, nonConst2) << std::endl;

    std::cout << "\n=== Test casi particolari ===" << std::endl;
    Fixed zero;
    Fixed negative(-5);
    std::cout << "zero: " << zero << std::endl;
    std::cout << "negative: " << negative << std::endl;
    std::cout << "zero == zero: " << (zero == zero) << std::endl;

    return 0;
}