//
// Created by Lenovo on 2/26/2022.
//

#include <iostream>
#include "Node.h"

Node::Node(int data) : data(data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
    this->color = 'R';
}

Node* Node::getUncle() {
    Node* parentNode = this->parent;
    if (parentNode) {
        Node* grandparent = parentNode->parent;
        if (grandparent) {
            if (!grandparent->left || !grandparent->right) {
                return nullptr;
            }
            if (grandparent->left->isEqual(parentNode)) {
                return grandparent->right;
            }
            return grandparent->left;
        }
    }
    return nullptr;
}

bool Node::isEqual(Node *node) {
    return this == node;
}

Node *Node::getGrandParent() {
    Node* parentNode = this->parent;
    if (parentNode) {
        Node* grandParent = parentNode->parent;
        return grandParent;
    }
    return nullptr;
}

bool Node::isRoot() {
    return !this->parent;
}


void Node::recolor() {
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




