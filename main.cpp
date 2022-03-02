#include <iostream>
#include "src/Node.h"
#include "src/RBTree.h"
#include <vector>

int main() {
    auto *tree = new RBTree<int>();
    std::vector<int> arr = {1, 1, 2, 3, 4, 5, 5, 2};
    for (int i = 0; i < arr.size(); i++) {
        tree->insert(arr[i], i);
    }

    tree->inorder();
}
