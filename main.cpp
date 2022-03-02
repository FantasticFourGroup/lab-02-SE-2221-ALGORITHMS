#include <iostream>
#include "src/Node.h"
#include "src/RBTree.h"
#include <vector>
#include <string>

int main() {
    std::vector<std::string> names = {"andy", "bob", "charlie", "david", "elizabeth", "andy", "frank", "george"};
    RBTree<std::string> tree = RBTree<std::string>();
    for (int i = 0; i < names.size(); i++) {
        tree.insert(names[i], i);
    }
    tree.inorder();
    std::cout << tree.searchElement("andy")->data << std::endl;
}
