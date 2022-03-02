//
// Created by Lenovo on 3/2/2022.
//

#ifndef REDBLACKTREE_TABLE_H
#define REDBLACKTREE_TABLE_H

#include "RBTree.h"
#include "Person.h"
#include "Node.h"
#include <string>
#include <vector>

class Table {
private:
    RBTree<std::string> nameTree;
    RBTree<std::string> usernameTree;
    RBTree<std::string> professionTree;

    std::vector<Person> records;

public:
    Table();

    void insert(Person person);

    RBTree<std::string> getNameTree();

    RBTree<std::string> getUsernameTree();

    RBTree<std::string> getProfessionTree();

    Node<std::string> *searchName(std::string name);

    Node<std::string> *searchUsername(std::string username);

    Node<std::string> *searchProfession(std::string profession);

    std::vector<Person> getRecords();
};


#endif //REDBLACKTREE_TABLE_H
