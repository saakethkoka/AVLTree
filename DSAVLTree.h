//
// Created by Saaketh Koka on 4/6/21.
//
#pragma once
#include "DSAVLTreeNode.h"

template<class A, class T>
class DSAVLTree{
private:
    DSAVLTreeNode<A,T> *root;
public:
    //constrtors - destructor
    DSAVLTree(const DSAVLTreeNode<A,T>* root = nullptr); //default constructor
    DSAVLTree(const DSAVLTree& otherTree); //copy constructor

    ~DSAVLTree(); //destructor

    //overloaded operators
    DSAVLTree<A,T> operator=(const DSAVLTree<A,T> &list2BCopied);


};

template<class A, class T>
DSAVLTree<A, T>::DSAVLTree(const DSAVLTreeNode<A, T> *root) {

}

template<class A, class T>
DSAVLTree<A, T>::DSAVLTree(const DSAVLTree &otherTree) {

}

template<class A, class T>
DSAVLTree<A, T>::~DSAVLTree() {

}

template<class A, class T>
DSAVLTree<A, T> DSAVLTree<A, T>::operator=(const DSAVLTree<A, T> &list2BCopied) {
    return DSAVLTree<A, T>();
}





