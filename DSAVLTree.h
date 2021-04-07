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

    // Rotation Methods:
    void rotateWithLeftChild(DSAVLTreeNode<A,T> *&node);
    void rotateWithRightChild(DSAVLTreeNode<A,T> *&node);
    void doubleWithLeftChild(DSAVLTree<A,T> *&node);
    void doubleWithRightChild(DSAVLTree<A,T> *&node);

    // Get Height of node:
    int getHeight(DSAVLTreeNode<A,T> *&node);


public:
    //constructors - destructor
    DSAVLTree(const DSAVLTreeNode<A,T>* root = nullptr); //default constructor
    DSAVLTree(const DSAVLTree& otherTree); //copy constructor
    ~DSAVLTree(); //destructor

    // Insertion methods:
    void insert(A key, T value);
    // Contains Method:
    bool contains(A key);

    //overloaded operators
    DSAVLTree<A,T> operator=(const DSAVLTree<A,T> &list2BCopied); //overloaded assignment operator

    //print operators
    void printInOrder(); // in order print
    void printPreOrder(); // pre order print


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
    if(getHeight(t->left) - getHeight(t->right) > 1){
        if(getHeight(t->left->left >= getHeight(t->left->right))){
            rotateWithLeftChild(t);
        }
        else{
            doubleWithLeftChild(t);
        }
    }
    else if(getHeight(t->right) - getHeight(t->left) > 1){
        if(getHeight(t->right->right >= getHeight(t->right->left))){
            rotateWithRightChild(t);
        }
        else{
            doubleWithRightChild(t);
        }
    }
    // TODO: figure out what to do with changing height
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

template<class A, class T>
int DSAVLTree<A, T>::getHeight(DSAVLTreeNode<A, T> *&node) {
    if(node == nullptr){
        return -1;
    }
    else{
        return node->height;
    }
}

// TODO: I have no idea if this is right:
template<class A, class T>
void DSAVLTree<A, T>::rotateWithLeftChild(DSAVLTreeNode<A, T> *&node) {
    DSAVLTreeNode<A,T> leftNode = node->left;
    node->left = leftNode.right;
    leftNode.right = node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    leftNode.height = std::max(getHeight(leftNode.left), node->height) + 1;
    node = leftNode;
}





