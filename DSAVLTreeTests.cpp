//
// Created by Saaketh Koka on 4/6/21.
//
#include "catch.hpp"
#include "DSAVLTreeNode.h"
#include "DSAVLTree.h"

TEST_CASE("DSAVLTree", "The DSAVLTree is a self balancing binary search tree"){
    SECTION("The DSAVLTree has a constructor which can generate the root node using a node"){
        DSAVLTree<int,int> test;
        REQUIRE(test.get_root() == nullptr);
        DSAVLTreeNode<int,int> node(15,54);
        DSAVLTreeNode<int,int> node1(57,98);
        DSAVLTreeNode<int,int> node2(114,337,&node,&node1);
        DSAVLTree<int,int> test2(&node2);
        REQUIRE(test2.get_root() != &node2);
        node2.get_key() = 557;
        REQUIRE(test2.get_root()->get_key() == 114);
    }

    SECTION("The DSAVLTree has a copy constructor which allows it to accuartly generate a deep copy of another DSAVLTree"){
        DSAVLTree<int,int> test;
        for(int i = 0; i < 1000; i++){
            test.insert(i,5*i);
        }
        DSAVLTree<int,int>  test_2(test);
        REQUIRE(test_2.get_root()->get_value() == test.get_root()->get_value());
    }
}