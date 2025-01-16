#include <iostream>
#include <cmath>

int main() {
    double number, result;

    std::cout << "Enter a number: ";
    std::cin >> number;

    if (number < 0) {
        std::cout << "Square root of negative numbers is not real." << std::endl;
    } else {
        result = std::sqrt(number);
        std::cout << "Square root of " << number << " is " << result << std::endl;
    }

    return 0;
}
