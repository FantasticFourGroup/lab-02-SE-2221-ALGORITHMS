//
// Created by Lenovo on 3/2/2022.
//

#ifndef REDBLACKTREE_PERSON_H
#define REDBLACKTREE_PERSON_H

#include <string>

class Person {
public:
    std::string name;
    std::string username;
    std::string profession;

    Person(
            std::string name,
            std::string username,
            std::string profession
    ) {
        this->name = name;
        this->username = username;
        this->profession = profession;
    }
};

#endif //REDBLACKTREE_PERSON_H
