//
// Created by Lenovo on 2/26/2022.
//

#ifndef REDBLACKTREE_RBTREE_H
#define REDBLACKTREE_RBTREE_H

#include "Node.h"

enum cases { ll, lr, rr, rl, none };

class RBTree {
private:
    Node* insertHelper(Node* root, int data);
    Node* insertRoot(int data);
    Node* searchElHelper(Node* root, int data);
    void inorderHelper(Node* root);
    cases getCase(Node* node);
public:
    Node* root;
    RBTree();
    void insert(int data);
    Node* searchElement(int data);
    void inorder();
    void rotateLeft(Node* node);
    void rotateRight(Node* node);
};


#endif //REDBLACKTREE_RBTREE_H
