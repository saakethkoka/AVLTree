#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Catch::Session().run();
    return 0;
}
