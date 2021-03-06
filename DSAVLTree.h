//
// Created by Saaketh Koka on 4/6/21.
//
#pragma once
#include <iostream>
#include <stdexcept>
#include "DSAVLTreeNode.h"

template<class A, class T>
class DSAVLTree{
private:
    DSAVLTreeNode<A,T> *root;

    // TODO: Track number of nodes in tree, this is needed when we output statistics in the demo.
    // Or we can caluclate the number of nodes when we want to output the stats (easier):
    int numNodes;

    void insert(A key, T value, DSAVLTreeNode<A,T> *&t);
    void balance(DSAVLTreeNode<A,T> *&t);


    //contains helper
    bool contains(const A& key, DSAVLTreeNode<A,T>*& node) const;

    //print methods
    void printPreOrder(const DSAVLTreeNode<A,T>* node) const;
    void printInOrder(const DSAVLTreeNode<A,T>* node) const;
    void printPostOrder(const DSAVLTreeNode<A,T>* node) const;

    // Rotation Methods:
    void rotateWithLeftChild(DSAVLTreeNode<A,T>*& node);
    void rotateWithRightChild(DSAVLTreeNode<A,T>*& node);
    void doubleWithLeftChild(DSAVLTreeNode<A,T>*& node);
    void doubleWithRightChild(DSAVLTreeNode<A,T>*& node);

    // Get Height of node:
    int getHeight(DSAVLTreeNode<A,T> *&node);

    // Clone
    DSAVLTreeNode<A,T>* clone(DSAVLTreeNode<A,T>*& node);

    //destructor helper
    void destructorHelper(DSAVLTreeNode<A,T>*& node);



public:
    //constructors - destructor
    DSAVLTree(DSAVLTreeNode<A,T>* root = nullptr); //default constructor
    DSAVLTree(DSAVLTree& otherTree); //copy constructor
    ~DSAVLTree(); //destructor

    /**
     * Inserts a key value pair into the tree at the proper location and then balances the tree.
     * @param key
     * @param value
     */
    void insert(A key, T value);

    /**
     * Inserts an AVLTree Node into the Tree and then balance's it.
     * @param DSAVLTreeNode
     */
    void insert(const DSAVLTreeNode<A,T>*& node);

    /**
     * Output's whether or not a certain key is found in the tree.
     * @param key
     * @return bool
     */
    bool contains(const A& key) const;

    /**
     * Assignment Operator
     * @param tree to be copied
     * @return DSAVLTree
     */
    DSAVLTree<A,T>& operator=(const DSAVLTree<A,T>& other); //overloaded assignment operator

    /**
     * Outputs the tree by printing each node the first time it is visited.
     */
    void printPreOrder() const;

    /**
     * Outputs the tree by printing each node in order.
     */
    void printInOrder() const;

    /**
     * Outputs the tree by printing each node after all children were visited.
     */
    void printPostOrder() const;

    /**
     * Returns a pointer to the root of the tree.
     * @return DSAVLTreeNode *
     */
    DSAVLTreeNode<A,T>* get_root() const;

};


template<class A, class T>
DSAVLTree<A, T>::DSAVLTree(DSAVLTreeNode<A, T> *targetNode) {
    if(targetNode == nullptr){
        root = nullptr;
        return;
    }
    this->root = clone(targetNode);
}


template<class A, class T>
DSAVLTree<A, T>::DSAVLTree(DSAVLTree &otherTree) {
    if(otherTree.root == nullptr){
        root = nullptr;
        return;
    }
    this->root = clone(otherTree.root);
}


template<class A, class T>
DSAVLTree<A, T>::~DSAVLTree() {
    destructorHelper(root);
}

template<class A, class T>
DSAVLTree<A, T>& DSAVLTree<A, T>::operator=(const DSAVLTree<A, T>& other) {
    if(this == &other){ //Checks to see if self = self
        return *this;
    }
    if(this->root != nullptr){
        this->~DSAVLTree<A,T>(); //deletes data
    }
    if(other->root == nullptr){
        this->root = nullptr; //makes root nullptr is other tree has no data
    }
    else {
        this->root = clone(other.root);
    }

    return *this;
}

template<class A, class T>
void DSAVLTree<A, T>::insert(A key, T value, DSAVLTreeNode<A, T> *&t) {
    if(t == nullptr){
        t = new DSAVLTreeNode<A,T>(key,value); // Once it finds an empty node it creates a new node there.
    }
    else if(t->key < key){
        insert(key, value, t->right); // Recursively searches for proper place to insert value.
    }
    else if(key < t->key){
        insert(key, value, t->left);
    }
    balance(t);
}


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
    t->height = std::max(getHeight(t->left), getHeight(t->right)) + 1; // Updates height
}

template<class A, class T>
void DSAVLTree<A, T>::printPreOrder() const{
    printPreOrder(root);
}

template<class A, class T>
void DSAVLTree<A, T>::printPreOrder(const DSAVLTreeNode<A, T>* node) const{
    if(node == nullptr){
        return;
    }
    std::cout << node->key << ": " << node->value << std::endl;
    printPreOrder(node->left);
    printPreOrder(node->right);
}

template<class A, class T>
void DSAVLTree<A,T>::printInOrder() const{
    printInOrder(root);
}

template<class A, class T>
void DSAVLTree<A, T>::printInOrder(const DSAVLTreeNode<A, T>* node) const{
    if(node == nullptr){
        return;
    }
    printInOrder(node->left);
    std::cout << node->key << ": " << node->value << std::endl;
    printInOrder(node->right);
}

template<class A, class T>
void DSAVLTree<A, T>::printPostOrder() const {
    printPostOrder(root);
}

template<class A, class T>
void DSAVLTree<A, T>::printPostOrder(const DSAVLTreeNode<A, T>* node) const {
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
void DSAVLTree<A, T>::insert(const DSAVLTreeNode<A, T> *&node) {
    insert(node->key, node->value, root);
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


template<class A, class T>
bool DSAVLTree<A, T>::contains(const A &key, DSAVLTreeNode<A, T> *&node) const {
    if(node == nullptr){
        return false;
    }
    if(node->key == key){
        return true;
    }
    if(node->key < key){
        return contains(key, node->right);
    }
    else{
        return contains(key, node->left);
    }
}

template<class A, class T>
bool DSAVLTree<A, T>::contains(const A &key) const{
    if(this->root->key == key){
        return true;
    }
    DSAVLTreeNode<A,T> *node = root;
    return contains(key, node);
}

template<class A, class T>
void DSAVLTree<A, T>::destructorHelper(DSAVLTreeNode<A, T> *&node) {
    if(node == nullptr){
        return;
    }
    destructorHelper(node->left);
    destructorHelper(node->right);
    delete node;
}

template<class A, class T>
DSAVLTreeNode<A, T> *DSAVLTree<A, T>::clone(DSAVLTreeNode<A, T>*& node) {
    if(node == nullptr){
        return nullptr;
    }
    DSAVLTreeNode<A,T>* left = clone(node->left);
    DSAVLTreeNode<A,T>* right = clone(node->right);
    return new DSAVLTreeNode<A,T>(node->key,node->value,left,right);
}

template<class A, class T>
DSAVLTreeNode<A, T> *DSAVLTree<A, T>::get_root() const{
    return root;
}




