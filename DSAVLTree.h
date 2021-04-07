//
// Created by Saaketh Koka on 4/6/21.
//
#pragma once
#include <iostream>
#include "DSAVLTreeNode.h"
#include <iostream>

template<class A, class T>
class DSAVLTree{
private:
    DSAVLTreeNode<A,T> *root;

    void insert(A key, T value, DSAVLTreeNode<A,T> *&t);
    void balance(DSAVLTreeNode<A,T> *&t);
    void printPreOrder(DSAVLTreeNode<A,T> *node);
public:
    //constructors - destructor
    DSAVLTree(const DSAVLTreeNode<A,T>* root = nullptr); //default constructor
    DSAVLTree(const DSAVLTree& otherTree); //copy constructor
    ~DSAVLTree(); //destructor

    // Insertion methods:
    void insert(A key, T value);

    //overloaded operators
    DSAVLTree<A,T> operator=(const DSAVLTree<A,T> &list2BCopied); //overladed assignment operator

    //print operators
    void printInOrder(); //in order print



    // Traversal Functions:
    void printPreOrder();


};

// TODO:
template<class A, class T>
DSAVLTree<A, T>::DSAVLTree(const DSAVLTreeNode<A, T> *targetNode) {

}

// TODO:
template<class A, class T>
DSAVLTree<A, T>::DSAVLTree(const DSAVLTree &otherTree) {

}

// TODO:
template<class A, class T>
DSAVLTree<A, T>::~DSAVLTree() {

}

template<class A, class T>
DSAVLTree<A, T> DSAVLTree<A, T>::operator=(const DSAVLTree<A, T> &list2BCopied) {
    return DSAVLTree<A, T>();
}

template<class A, class T>
void DSAVLTree<A, T>::insert(A key, T value, DSAVLTreeNode<A, T> *&t) {
    if(t == nullptr){
        t = new DSAVLTreeNode<A,T>(key,value);
    }
    else if(t->key < key){
        insert(key, value, t->right);
    }
    else if(key < t->key){
        insert(key, value, t->left);
    }
    balance(t);
}

// TODO:
template<class A, class T>
void DSAVLTree<A, T>::balance(DSAVLTreeNode<A, T> *&t) {

}

template<class A, class T>
void DSAVLTree<A, T>::printPreOrder() {
    printPreOrder(root);
}

template<class A, class T>
void DSAVLTree<A, T>::printPreOrder(DSAVLTreeNode<A, T> *node) {
    if(node == nullptr){
        return;
    }
    std::cout << node->key << ": " << node->value << std::endl;
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template<class A, class T>
void DSAVLTree<A, T>::insert(A key, T value) {

}





