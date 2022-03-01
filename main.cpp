#include <iostream>
#include "src/Node.h"
#include "src/RBTree.h"

int main() {
    RBTree<int>* tree = new RBTree<int>();
    tree->insert(3);
    tree->insert(21);
    tree->insert(35);
    tree->insert(15);
    tree->insert(7);
    tree->inorder();
}
