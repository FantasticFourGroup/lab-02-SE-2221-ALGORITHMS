//
// Created by Lenovo on 2/26/2022.
//

#include "Node.h"
#include <vector>

template <typename T>
Node<T>::Node(T data) : data(data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->color = 'R';
    this->indexes = {};
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
Node<T> *Node<T>::addLeft(T val, int index) {
    Node *newNode = new Node(val);
    newNode->parent = this;
    this->left = newNode;
    newNode->indexes.push_back(index);
    return newNode;
}


template<typename T>
Node<T> *Node<T>::addRight(T val, int index) {
    Node *newNode = new Node(val);
    newNode->parent = this;
    this->right = newNode;
    newNode->indexes.push_back(index);
    return newNode;
}


template class Node<int>;


