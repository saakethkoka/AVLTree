#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "DSAVLTree.h"

int main(int argc, char* argv[]) {
    if(argc == 1){
        Catch::Session().run();
    }
    return 0;
}
