#include <iostream>
#include "src/Node.h"
#include "src/RBTree.h"
#include "src/Table.h"
#include "src/Generator.h"

int main() {
    Table table = Table();
    for (int i = 0; i < 50000; i++) {
        if (i % 100000 == 0) {
            table.insert(Person("Hans", "RubikParsley", "Student"));
            continue;
        }
        std::string name = gen_random(12);
        std::string username = gen_random(12);
        std::string profession = gen_random(12);
        Person person = Person(name, username, profession);
        table.insert(person);
        if (i % 10000 == 0) {
            std::cout << i << std::endl;
        }
    }
    std::cout << "Data: " << table.searchName("Hans")->data << std::endl;
    std::cout << "Indexes: [";
    for (int i = 0; i < table.searchName("Hans")->indexes.size(); i++) {
        std::cout << table.searchName("Hans")->indexes[i];
        if (i != table.searchName("Hans")->indexes.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
    std::cout << "Color: " << table.searchName("Hans")->color << std::endl;
}
