//
// Created by Lenovo on 2/26/2022.
//

#ifndef REDBLACKTREE_NODE_H
#define REDBLACKTREE_NODE_H

#include <vector>
#include <cereal/archives/binary.hpp>

template<typename T>
class Node {
public:
    explicit Node<T>(T data);

    T data;
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

    template <typename Archive>
    void serialize(Archive &archive) {
        archive(data, left, right, parent, color, indexes);
    }
};


#endif //REDBLACKTREE_NODE_H
