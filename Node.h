//
// Created by Lenovo on 2/26/2022.
//

#ifndef REDBLACKTREE_NODE_H
#define REDBLACKTREE_NODE_H

class Node {
public:
    Node(int data);
    int data;
    Node* left;
    Node* right;
    Node* parent;
    char color;

    Node* getUncle();
    Node* getGrandParent();
    bool isEqual(Node* node);
    bool isRoot();
    void recolor();
};


#endif //REDBLACKTREE_NODE_H
