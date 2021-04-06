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

public:
    DSAVLTreeNode(A key, T value, DSAVLTreeNode* after = nullptr, DSAVLTreeNode* before = nullptr);
};

template<class A, class T>
DSAVLTreeNode<A, T>::DSAVLTreeNode(A key, T value, DSAVLTreeNode *left, DSAVLTreeNode *right) {
    this->key = key;
    this->value = value;
    this->left = left;
    this->right = right;
}





