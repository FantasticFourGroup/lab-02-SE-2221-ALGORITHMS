//
// Created by Lenovo on 2/26/2022.
//

#include <iostream>
#include "RBTree.h"
#include "Node.h"

RBTree::RBTree() {
    this->root = nullptr;
}

Node* RBTree::insertRoot(int data) {
    this->root = new Node(data);
    return this->root;
}

Node* RBTree::insertHelper(Node* rootNode, int data) {
    if (data > rootNode->data) {
        if (!rootNode->right) {
            rootNode->right = new Node(data);
            rootNode->right->parent = rootNode;
            return rootNode->right;
        }
        return this->insertHelper(rootNode->right, data);
    }

    if (!rootNode->left) {
        rootNode->left = new Node(data);
        rootNode->left->parent = rootNode;
        return rootNode->left;
    }

    return this->insertHelper(rootNode->left, data);
}

void RBTree::insert(int data) {
    if (!this->root) {
        this->insertRoot(data);
        this->root->color = 'B';
        return;
    }
    Node* insertedNode = this->insertHelper(this->root, data);
    Node* parent = insertedNode->parent;
    Node* uncle = insertedNode->getUncle();
    if (uncle && parent) {
        if (uncle->color == 'R' && parent->color == 'R') {
            insertedNode->recolor();
        }
    }

    else if (parent && parent->color == 'R') {
        cases caseType = this->getCase(insertedNode);
        Node* parentNode = insertedNode->parent;
        Node* grandParentNode = insertedNode->getGrandParent();
        switch (caseType) {
            case ll:
                if (grandParentNode) {
                    this->rotateRight(grandParentNode);
                    if (this->root->isEqual(grandParentNode)) {
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
                    if (this->root->isEqual(grandParentNode)) {
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
                    if (this->root->isEqual(grandParentNode)) {
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
                    if (this->root->isEqual(grandParentNode)) {
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

Node* RBTree::searchElement(int data) {
    return this->searchElHelper(this->root, data);
}

Node* RBTree::searchElHelper(Node *root, int data) {
    if (!root) return nullptr;

    if (data == root->data) return root;

    if (data > root->data) {
        return searchElHelper(root->right, data);
    }

    return searchElHelper(root->left, data);
}

void RBTree::inorderHelper(Node* root) {
    if (!root) return;
    this->inorderHelper(root->left);
    std::cout << "{" << root->data << ", " << root->color << "}" << std::endl;
    this->inorderHelper(root->right);
}


void RBTree::inorder() {
    this->inorderHelper(this->root);
    std::cout << "\n";
}

void RBTree::rotateLeft(Node *node) {
    Node* rightChild = node->right;
    Node* parentNode = node->parent;
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

void RBTree::rotateRight(Node *node) {
    Node* leftChild = node->left;
    Node* parentNode = node->parent;
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

cases RBTree::getCase(Node *node) {
    Node* parentNode = node->parent;
    Node* grandParentNode = node->getGrandParent();

    if (parentNode && grandParentNode) {
        if (grandParentNode->left->isEqual(parentNode) && parentNode->left->isEqual(node)) {
            return ll;
        }

        if (grandParentNode->left->isEqual(parentNode) && parentNode->right->isEqual(node)) {
            return lr;
        }

        if (grandParentNode->right->isEqual(parentNode) && parentNode->left->isEqual(node)) {
            return rl;
        }

        if (grandParentNode->right->isEqual(parentNode) && parentNode->right->isEqual(node)) {
            return rr;
        }
    }

    return none;
}




