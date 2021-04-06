cmake_minimum_required(VERSION 3.17)
project(AVLTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(AVLTree main.cpp DSAVLTree.h DSAVLTreeNode.h catch.hpp DSAVLTreeTests.cpp)