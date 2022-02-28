#include <iostream>
#include "RBTree.h"

int main() {
    RBTree* tree = new RBTree();
    for (int i = 0; i < 10; i++) {
        tree->insert(i);
    }
    tree->inorder();

    std::cout << tree->root->data << std::endl;
}
