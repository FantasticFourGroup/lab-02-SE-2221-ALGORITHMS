//
// Created by Lenovo on 2/28/2022.
//

#include "RBTree.h"
#include "Node.h"
#include <iostream>
#include <utility>

template<typename T>
RBTree<T>::RBTree() {
    this->root = nullptr;
}

template<typename T>
Node<T> *RBTree<T>::insertRoot(T data, int index) {
    this->root = new Node<T>(data);
    this->root->indexes.push_back(index);
    return this->root;
}

template<typename T>
std::pair<Node<int> *, bool> *RBTree<T>::insertHelper(Node<T> *rootNode, T data, int index) {
    if (data == rootNode->data) {
        rootNode->indexes.push_back(index);
        return new std::pair<Node<T> *, bool>(rootNode, true);
    }
    if (data > rootNode->data) {
        if (!rootNode->right) {
            Node<T> *addedNode = rootNode->addRight(data, index);
            return new std::pair<Node<T> *, bool>(addedNode, false);
        }
        return this->insertHelper(rootNode->right, data, index);
    }

    if (!rootNode->left) {
        Node<T> *addedNode = rootNode->addLeft(data, index);
        return new std::pair<Node<T> *, bool>(addedNode, false);
    }

    return this->insertHelper(rootNode->left, data, index);
}

template<typename T>
void RBTree<T>::insert(T data, int index) {
    if (!this->root) {
        this->insertRoot(data, index);
        this->root->color = 'B';
        return;
    }
    std::pair<Node<T> *, bool> *pair = this->insertHelper(this->root, data, index);
    Node<T> *insertedNode = pair->first;
    bool isSameNode = pair->second;
    if (isSameNode) {
        return;
    }
    Node<T> *parent = insertedNode->parent;
    Node<T> *uncle = insertedNode->getUncle();
    if (uncle && parent) {
        if (uncle->color == 'R' && parent->color == 'R') {
            insertedNode->recolor();
        }
    } else if (parent && parent->color == 'R') {
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

template<typename T>
Node<T> *RBTree<T>::searchElHelper(Node<T> *rootNode, T data) {
    if (!rootNode) return nullptr;

    if (data == rootNode->data) return rootNode;

    if (data > rootNode->data) {
        return searchElHelper(rootNode->right, data);
    }

    return searchElHelper(rootNode->left, data);
}

template<typename T>
void RBTree<T>::inorderHelper(Node<T> *rootNode) {
    if (!rootNode) return;
    this->inorderHelper(rootNode->left);
    std::cout << "{" << rootNode->data << ", ";
    std::cout << "[";
    for (int i = 0; i < rootNode->indexes.size(); i++) {
        std::cout << rootNode->indexes[i];
        if (i != rootNode->indexes.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "], ";
    std::cout << rootNode->color << "}" << std::endl;
    this->inorderHelper(rootNode->right);
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