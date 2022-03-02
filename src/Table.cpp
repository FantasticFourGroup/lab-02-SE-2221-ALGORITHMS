//
// Created by Lenovo on 3/2/2022.
//

#include "Table.h"

Table::Table() {
    nameTree = {};
    usernameTree = {};
    professionTree = {};
}

void Table::insert(Person person) {
    records.push_back(person);
    int index = records.size();
    nameTree.insert(person.name, index - 1);
    usernameTree.insert(person.username, index);
    professionTree.insert(person.profession, index);
}

Node<std::string> *Table::searchName(std::string name) {
    return nameTree.searchElement(name);
}

Node<std::string> *Table::searchUsername(std::string username) {
    return usernameTree.searchElement(username);
}

Node<std::string> *Table::searchProfession(std::string profession) {
    return professionTree.searchElement(profession);
}

RBTree<std::string> Table::getNameTree() {
    return nameTree;
}

RBTree<std::string> Table::getUsernameTree() {
    return usernameTree;
}

RBTree<std::string> Table::getProfessionTree() {
    return professionTree;
}

std::vector<Person> Table::getRecords() {
    return records;
}

