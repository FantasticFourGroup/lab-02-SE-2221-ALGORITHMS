//
// Created by Lenovo on 3/1/2022.
//

#include "gtest/gtest.h"
#include "RBTree.h"

TEST(RBTreeTest, RBTreeTest) {
    RBTree<int>* tree = new RBTree<int>();
    tree->insert(3);
    tree->insert(21);
    tree->insert(35);
    tree->insert(15);
    tree->insert(7);
}