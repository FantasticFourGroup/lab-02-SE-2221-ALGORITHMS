//
// Created by Lenovo on 2/28/2022.
//

#ifndef REDBLACKTREE_RBTREE_H
#define REDBLACKTREE_RBTREE_H

#include "Node.h"

enum cases { ll, lr, rr, rl, none };

template <typename T>
class RBTree {
private:
    Node<T> *insertHelper(Node<T> *root, T data);
    Node<T> *insertRoot(T data);
    Node<T> *searchElHelper(Node<T> *root, T data);
    void inorderHelper(Node<T> *root);
    cases getCase(Node<T> *node);
public:
    Node<T> *root;
    RBTree<T>();
    void insert(T data);
    Node<T> *searchElement(T data);
    void inorder();
    void rotateLeft(Node<T> *node);
    void rotateRight(Node<T> *node);
};


#endif //REDBLACKTREE_RBTREE_H
