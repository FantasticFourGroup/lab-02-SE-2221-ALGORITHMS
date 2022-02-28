#include <iostream>
#include "RBTree.h"

int main() {
    RBTree* tree = new RBTree();
    tree->insert(3);
    tree->insert(21);
    tree->insert(32);
    tree->insert(15);
    tree->inorder();

    std::cout << tree->root->data << std::endl;
}
