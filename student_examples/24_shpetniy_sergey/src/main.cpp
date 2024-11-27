#include "req.hpp"
#include <iostream>

int main()
{
    try {
    std::cout << "Main entered" << std::endl;
    requests::getRequest("s9603567", "s9603770", "2024-11-25");
    } catch (const std::exception& ex) {
    std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}
