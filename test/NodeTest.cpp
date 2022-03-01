//
// Created by Lenovo on 3/1/2022.
//

#include "gtest/gtest.h"
#include "Node.h"

TEST(NodeTest, NodeTest) {
    Node<int> *node = new Node<int>(1);
    EXPECT_EQ(node->data, 1);
    EXPECT_EQ(node->left, nullptr);
    EXPECT_EQ(node->right, nullptr);
    delete node;
}