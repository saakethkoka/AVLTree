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

    //contains helper
    bool contains(const A& key, const DSAVLTreeNode<A,T>*& node) const;

    //print methods
    void printPreOrder(const DSAVLTreeNode<A,T>* node) const;
    void printInOrderHelper(DSAVLTreeNode<A,T>* node);
    void printPostOrder(const DSAVLTreeNode<A,T>* node) const;

    // Rotation Methods:
    void rotateWithLeftChild(DSAVLTreeNode<A,T>*& node);
    void rotateWithRightChild(DSAVLTreeNode<A,T>*& node);
    void doubleWithLeftChild(DSAVLTreeNode<A,T>*& node);
    void doubleWithRightChild(DSAVLTreeNode<A,T>*& node);

    // Get Height of node:
    int getHeight(DSAVLTreeNode<A,T> *&node);


public:
    //constructors - destructor
    DSAVLTree(DSAVLTreeNode<A,T>* root = nullptr); //default constructor
    DSAVLTree(const DSAVLTree& otherTree); //copy constructor
    ~DSAVLTree(); //destructor

    // Insertion methods:
    void insert(A key, T value);
    void insert(const DSAVLTreeNode<A,T>*& node);

    // Contains Method:
    bool contains(const A& key) const;

    //overloaded operators
    DSAVLTree<A,T> operator=(const DSAVLTree<A,T> &list2BCopied); //overloaded assignment operator

    //print operators
    void printPreOrder() const; // pre order print
    void printInOrder(); // in order print
    void printPostOrder() const; //post order print


};

// TODO:
template<class A, class T>
DSAVLTree<A, T>::DSAVLTree(DSAVLTreeNode<A, T> *targetNode) {
    root = targetNode;
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
        if(getHeight(t->left->left) >= getHeight(t->left->right)){
            rotateWithLeftChild(t);
        }
        else{
            doubleWithLeftChild(t);
        }
    }
    else if(getHeight(t->right) - getHeight(t->left) > 1){
        if(getHeight(t->right->left) >= getHeight(t->right->right)){
            doubleWithRightChild(t);

        }
        else{
            rotateWithRightChild(t);
        }
    }
    t->height = std::max(getHeight(t->left), getHeight(t->right)) + 1;
}

template<class A, class T>
void DSAVLTree<A, T>::printPreOrder() const{
    printPreOrder(root);
}

template<class A, class T>
void DSAVLTree<A, T>::printPreOrder(const DSAVLTreeNode<A, T> *node) const{
    if(node == nullptr){
        return;
    }
    std::cout << node->key << ": " << node->value << std::endl;
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template<class A, class T>
void DSAVLTree<A,T>::printInOrder() {
    printInOrderHelper(this->root);
}

template<class A, class T>
void DSAVLTree<A, T>::printInOrderHelper(DSAVLTreeNode<A, T> *node){
    if(node == nullptr){
        return;
    }
    printInOrderHelper(node->left);
    std::cout << node->key << ": " << node->value << std::endl;
    printInOrderHelper(node->right);
}

template<class A, class T>
void DSAVLTree<A, T>::printPostOrder() const {
    printPostOrder(root);
}

template<class A, class T>
void DSAVLTree<A, T>::printPostOrder(const DSAVLTreeNode<A, T> *node) const {
    if(node == nullptr){
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    std::cout << node->key << ": " << node->value << std::endl;
}



template<class A, class T>
void DSAVLTree<A, T>::insert(A key, T value) {
    insert(key, value, root);
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

template<class A, class T>
void DSAVLTree<A, T>::rotateWithLeftChild(DSAVLTreeNode<A, T>*& node) {
    DSAVLTreeNode<A,T> *leftNode = node->left;
    node->left = leftNode->right;
    leftNode->right = node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    leftNode->height = std::max(getHeight(leftNode->left), node->height) + 1;
    node = leftNode;
}

template<class A, class T>
void DSAVLTree<A, T>::rotateWithRightChild(DSAVLTreeNode<A, T> *&node) {
    DSAVLTreeNode<A,T> *rightNode = node->right;
    node->right = rightNode->left;
    rightNode->left = node;
    node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
    rightNode->height = std::max(getHeight(rightNode->right), node->height) + 1;
    node = rightNode;
}

template<class A, class T>
void DSAVLTree<A, T>::doubleWithLeftChild(DSAVLTreeNode<A, T> *&node) {
    rotateWithRightChild(node->left);
    rotateWithLeftChild(node);
}

template<class A, class T>
void DSAVLTree<A, T>::doubleWithRightChild(DSAVLTreeNode<A, T> *&node) {
    rotateWithLeftChild(node->right);
    rotateWithRightChild(node);
}

//TODO contains
template<class A, class T>
bool DSAVLTree<A, T>::contains(const A &key, const DSAVLTreeNode<A, T> *&node) const {
    return false;
}

template<class A, class T>
bool DSAVLTree<A, T>::contains(const A &key) const{
    if(this->root->key)
    return false;
}










