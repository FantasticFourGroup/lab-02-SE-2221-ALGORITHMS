#include <iostream>
#include "Node.h"
#include "RBTree.h"

int main() {
    RBTree<int>* tree = new RBTree<int>();
    tree->insert(3);
    tree->insert(21);
    tree->insert(35);
    tree->insert(15);
    tree->inorder();
}
