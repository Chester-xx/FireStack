// launch.json config to app1.exe | when working on other projects remember to change the exe name
#include <iostream>
#include "math.h"
#include "memory.h"

int main() {
    
    std::cout << "6 to the power of 3 : " << math::pow(6.5, 3) << std::endl;
    int x = 19;
    std::cout << memory::pAddress(x) << std::endl;
    // can i deref the actual address?? - yes
    std::cout << *memory::pAddress(x) << std::endl;

    return EXIT_SUCCESS;
}
