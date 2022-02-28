//
// Created by Lenovo on 2/26/2022.
//

#ifndef REDBLACKTREE_NODE_H
#define REDBLACKTREE_NODE_H

template <typename T>
class Node {
public:
    explicit Node<T>(T data);
    int data;
    Node<T> *left;
    Node<T> *right;
    Node<T> *parent;
    char color{};

    Node<T> *getUncle();
    Node<T> *getGrandParent();
    bool isRoot();
    void recolor();
    void addLeft(T val);
    void addRight(T val);
};


#endif //REDBLACKTREE_NODE_H
