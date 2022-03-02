//
// Created by Lenovo on 2/26/2022.
//

#ifndef REDBLACKTREE_NODE_H
#define REDBLACKTREE_NODE_H

#include <vector>

template<typename T>
class Node {
public:
    explicit Node<T>(T data);

    int data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    char color{};
    std::vector<int> indexes;

    Node<T> *getUncle();

    Node<T> *getGrandParent();

    bool isRoot();

    void recolor();

    Node<T> *addLeft(T val, int index);

    Node<T> *addRight(T val, int index);
};


#endif //REDBLACKTREE_NODE_H
