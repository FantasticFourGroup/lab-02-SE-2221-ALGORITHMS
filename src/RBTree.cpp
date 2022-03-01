//
// Created by Lenovo on 2/28/2022.
//

#include <iostream>
#include "RBTree.h"
#include "Node.h"

template <typename T>
RBTree<T>::RBTree() {
    this->root = nullptr;
}

template <typename T>
Node<T> *RBTree<T>::insertRoot(T data) {
    this->root = new Node<T>(data);
    return this->root;
}

template <typename T>
Node<T> *RBTree<T>::insertHelper(Node<T> *rootNode, T data) {
    if (data > rootNode->data) {
        if (!rootNode->right) {
            rootNode->right = new Node<T>(data);
            rootNode->right->parent = rootNode;
            return rootNode->right;
        }
        return this->insertHelper(rootNode->right, data);
    }

    if (!rootNode->left) {
        rootNode->left = new Node<T>(data);
        rootNode->left->parent = rootNode;
        return rootNode->left;
    }

    return this->insertHelper(rootNode->left, data);
}

template <typename T>
void RBTree<T>::insert(T data) {
    if (!this->root) {
        this->insertRoot(data);
        this->root->color = 'B';
        return;
    }
    Node<T> *insertedNode = this->insertHelper(this->root, data);
    Node<T> *parent = insertedNode->parent;
    Node<T> *uncle = insertedNode->getUncle();
    if (uncle && parent) {
        if (uncle->color == 'R' && parent->color == 'R') {
            insertedNode->recolor();
        }
    }

    else if (parent && parent->color == 'R') {
        cases caseType = this->getCase(insertedNode);
        Node<T> *parentNode = insertedNode->parent;
        Node<T> *grandParentNode = insertedNode->getGrandParent();
        switch (caseType) {
            case ll:
                if (grandParentNode) {
                    this->rotateRight(grandParentNode);
                    if (this->root == grandParentNode) {
                        this->root = parentNode;
                    }
                    char tempColor = parentNode->color;
                    parentNode->color = grandParentNode->color;
                    grandParentNode->color = tempColor;
                }
                break;
            case lr:
                if (parentNode) {
                    this->rotateLeft(parentNode);
                }

                if (grandParentNode) {
                    parentNode = insertedNode;
                    this->rotateRight(grandParentNode);
                    if (this->root == grandParentNode) {
                        this->root = parentNode;
                    }
                    char tempColor = parentNode->color;
                    parentNode->color = grandParentNode->color;
                    grandParentNode->color = tempColor;
                }
                break;
            case rr:
                if (grandParentNode) {
                    this->rotateLeft(grandParentNode);
                    if (this->root == grandParentNode) {
                        this->root = parentNode;
                    }
                    char tempColor = parentNode->color;
                    parentNode->color = grandParentNode->color;
                    grandParentNode->color = tempColor;
                }
                break;
            case rl:
                if (parentNode) {
                    this->rotateRight(parentNode);
                }
                if (grandParentNode) {
                    parentNode = insertedNode;
                    this->rotateLeft(grandParentNode);
                    if (this->root == grandParentNode) {
                        this->root = parentNode;
                    }
                    char tempColor = parentNode->color;
                    parentNode->color = grandParentNode->color;
                    grandParentNode->color = tempColor;
                }
                break;
            case none:
                break;
        }
    }
}

template <typename T>
Node<T> *RBTree<T>::searchElement(T data) {
    return this->searchElHelper(this->root, data);
}

template <typename T>
Node<T> *RBTree<T>::searchElHelper(Node<T> *root, T data) {
    if (!root) return nullptr;

    if (data == root->data) return root;

    if (data > root->data) {
        return searchElHelper(root->right, data);
    }

    return searchElHelper(root->left, data);
}

template <typename T>
void RBTree<T>::inorderHelper(Node<T> *root) {
    if (!root) return;
    this->inorderHelper(root->left);
    std::cout << "{" << root->data << ", " << root->color << "}" << std::endl;
    this->inorderHelper(root->right);
}


template <typename T>
void RBTree<T>::inorder() {
    this->inorderHelper(this->root);
    std::cout << "\n";
}

template <typename T>
void RBTree<T>::rotateLeft(Node<T> *node) {
    Node<T> *rightChild = node->right;
    Node<T> *parentNode = node->parent;
    rightChild->parent = parentNode;
    if (parentNode) {
        if (parentNode->left == node) {
            parentNode->left = rightChild;
        } else {
            parentNode->right = rightChild;
        }
    }
    node->parent = rightChild;
    node->right = rightChild->left;
    if (rightChild->left) {
        rightChild->left->parent = node;
    }
    rightChild->left = node;
}

template <typename T>
void RBTree<T>::rotateRight(Node<T> *node) {
    Node<T> *leftChild = node->left;
    Node<T> *parentNode = node->parent;
    leftChild->parent = parentNode;
    if (parentNode) {
        if (parentNode->left == node) {
            parentNode->left = leftChild;
        } else {
            parentNode->right = leftChild;
        }
    }
    node->parent = leftChild;
    node->left = leftChild->right;
    if (leftChild->right) {
        leftChild->right->parent = node;
    }
    leftChild->right = node;
}

template <typename T>
cases RBTree<T>::getCase(Node<T> *node) {
    Node<T> *parentNode = node->parent;
    Node<T> *grandParentNode = node->getGrandParent();

    if (parentNode && grandParentNode) {
        if (grandParentNode->left == parentNode && parentNode->left == node) {
            return ll;
        }

        if (grandParentNode->left == parentNode && parentNode->right == node) {
            return lr;
        }

        if (grandParentNode->right == parentNode && parentNode->left == node) {
            return rl;
        }

        if (grandParentNode->right == parentNode && parentNode->right == node) {
            return rr;
        }
    }

    return none;
}

template class RBTree<int>;