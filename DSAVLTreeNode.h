//
// Created by Saaketh Koka on 4/6/21.
//

#pragma once
#include <iostream>

template<class A, class T>
class DSAVLTreeNode{
    template<class U, class Y> friend class DSAVLTree;
private:
    A key;
    T value;
    DSAVLTreeNode<A,T>* left;
    DSAVLTreeNode<A,T>* right;
    int height;

public:
    DSAVLTreeNode(A key, T value, DSAVLTreeNode* after = nullptr, DSAVLTreeNode* before = nullptr);

    //overloaded operators
    bool operator==(const DSAVLTreeNode<A,T>*& other) const;

    //acessors
    A& get_key();
    T& get_value();
    DSAVLTreeNode<A,T>*& get_left();
    DSAVLTreeNode<A,T>*& get_right();

};

template<class A, class T>
DSAVLTreeNode<A, T>::DSAVLTreeNode(A key, T value, DSAVLTreeNode *left, DSAVLTreeNode *right) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
    this->height = 0;
}
//acessors
template<class A, class T>
A& DSAVLTreeNode<A, T>::get_key(){
    return key;
}

template<class A, class T>
T& DSAVLTreeNode<A, T>::get_value(){
    return value;
}

template<class A, class T>
DSAVLTreeNode<A, T>*& DSAVLTreeNode<A, T>::get_left(){
    return left;
}

template<class A, class T>
DSAVLTreeNode<A, T>*& DSAVLTreeNode<A, T>::get_right(){
    return right;
}













