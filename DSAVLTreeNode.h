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

    //acessors
    A& get_key() const;
    T& get_value() const;
    DSAVLTreeNode<A,T>* get_left() const;
    DSAVLTreeNode<A,T>* get_right() const;

    //mutators
    void set_key(const A& key);
    void set_val(const T& val);
    void set_left(const DSAVLTreeNode<A,T>*& left);
    void set_right(const DSAVLTreeNode<A,T>*& right);
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
A &DSAVLTreeNode<A, T>::get_key() const {
    return key;
}

template<class A, class T>
T &DSAVLTreeNode<A, T>::get_value() const {
    return value;
}

template<class A, class T>
DSAVLTreeNode<A, T> *DSAVLTreeNode<A, T>::get_left() const {
    return left;
}

template<class A, class T>
DSAVLTreeNode<A, T> *DSAVLTreeNode<A, T>::get_right() const {
    return right;
}

//mutators
template<class A, class T>
void DSAVLTreeNode<A, T>::set_key(const A &key) {
    this->key = key;
}

template<class A, class T>
void DSAVLTreeNode<A, T>::set_val(const T &val) {
    this->value = val;
}

template<class A, class T>
void DSAVLTreeNode<A, T>::set_left(const DSAVLTreeNode<A, T> *&left) {
    this->left = left;
}

template<class A, class T>
void DSAVLTreeNode<A, T>::set_right(const DSAVLTreeNode<A, T> *&right) {
    this->right = right;
}











