#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "catch.hpp"
#include "DSAVLTree.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Catch::Session().run();
    DSAVLTree<int, int> tree;
    for(int i = 0; i < 5; i++){
        tree.insert(i,2);
    }
    tree.printInOrder();
    std::cout << std::endl;
    tree.printPreOrder();
    std::cout << std::endl;
    tree.printPostOrder();
    return 0;
}
