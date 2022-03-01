//
// Created by Lenovo on 2/26/2022.
//

#include "Node.h"

template <typename T>
Node<T>::Node(T data) : data(data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->color = 'R';
}

template <typename T>
Node<T> *Node<T>::getUncle() {
    Node* parentNode = this->parent;
    if (parentNode) {
        Node* grandparent = parentNode->parent;
        if (grandparent) {
            if (!grandparent->left || !grandparent->right) {
                return nullptr;
            }
            if (grandparent->left == parentNode) {
                return grandparent->right;
            }
            return grandparent->left;
        }
    }
    return nullptr;
}

template <typename T>
Node<T> *Node<T>::getGrandParent() {
    Node* parentNode = this->parent;
    if (parentNode) {
        Node* grandParent = parentNode->parent;
        return grandParent;
    }
    return nullptr;
}

template <typename T>
bool Node<T>::isRoot() {
    return !this->parent;
}


template <typename T>
void Node<T>::recolor() {
    if (this->isRoot()) return;
    Node* parentNode = this->parent;
    Node* uncleNode = this->getUncle();
    Node* grandParentNode = this->getGrandParent();
    if (parentNode && uncleNode && grandParentNode) {
        parentNode->color = 'B';
        uncleNode->color = 'B';
        if (!grandParentNode->isRoot()) grandParentNode->color = 'R';
        grandParentNode->recolor();
    }
}

template<typename T>
void Node<T>::addLeft(T val) {
    Node* newNode = new Node(val);
    newNode->parent = this;
    this->left = newNode;
    this->recolor();
}


template<typename T>
void Node<T>::addRight(T val) {
    Node* newNode = new Node(val);
    newNode->parent = this;
    this->right = newNode;
    this->recolor();
}


template class Node<int>;


