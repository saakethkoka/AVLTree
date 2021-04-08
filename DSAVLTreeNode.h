//
// Created by Saaketh Koka on 4/6/21.
//

#pragma once

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
    void calc_height();
};

template<class A, class T>
DSAVLTreeNode<A, T>::DSAVLTreeNode(A key, T value, DSAVLTreeNode *left, DSAVLTreeNode *right) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
    this->height = 0;
}

//TODO do we need this?
template<class A, class T>
void DSAVLTreeNode<A, T>::calc_height() { //This calulates height
    if(this->left == nullptr && this->right == nullptr){
        height = 0;
    }
    this->left->calc_height();
    this->right->calc_height();
    height = std::max(this->left->height, this->right->height) + 1;
}









