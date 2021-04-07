#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "DSAVLTree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Catch::Session().run();
    DSAVLTree<int, int> tress;
    for(int i = 0; i < 1000; i++){
        tress.insert(i,i);
    }
    std::cout << tress.contains(32) << std::endl;
    DSAVLTree<int,int> newTree = tress;
    return 0;

}
