//
// Created by Lenovo on 2/28/2022.
//

#ifndef REDBLACKTREE_RBTREE_H
#define REDBLACKTREE_RBTREE_H

#include "Node.h"
#include <utility>

enum cases { ll, lr, rr, rl, none };

template <typename T>
class RBTree {
private:
    std::pair<Node<T> *, bool> *insertHelper(Node<T> *root, T data, int index);

    Node<T> *insertRoot(T data, int index);

    Node<T> *searchElHelper(Node<T> *rootNode, T data);

    void inorderHelper(Node<T> *rootNode);

    cases getCase(Node<T> *node);

public:
    Node<T> *root;

    RBTree<T>();

    void insert(T data, int index);

    Node<T> *searchElement(T data);

    void inorder();

    void rotateLeft(Node<T> *node);

    void rotateRight(Node<T> *node);
};


#endif //REDBLACKTREE_RBTREE_H
