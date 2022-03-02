#include <iostream>
#include "src/Node.h"
#include "src/RBTree.h"
#include <vector>
#include <string>
#include "src/Table.h"
#include "src/Person.h"

int main() {
    Table table = Table();
    table.insert(Person("John", "Smith", "Sailor"));
    table.insert(Person("Jane", "Doe", "Engineer"));
    table.insert(Person("John", "Doe", "Engineer"));
    table.insert(Person("John", "Lennon", "Singer"));
    Node<std::string> *node = table.searchName("John");
    table.getNameTree().inorder();
}
