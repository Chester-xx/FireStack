// launch.json config to app1.exe | when working on other projects remember to change the exe name
#include <iostream>
#include "math.h"

int main() {
    std::cout << "Test" << std::endl;
    std::cout << "Square call 2 : " << math::sqr(2) << std::endl;
    std::cout << "6 to the power of 3 : " << math::pow(6.5, 3) << std::endl;

    return EXIT_SUCCESS;
}