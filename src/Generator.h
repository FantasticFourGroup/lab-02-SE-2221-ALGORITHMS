//
// Created by Lenovo on 3/3/2022.
//

#ifndef REDBLACKTREE_GENERATOR_H
#define REDBLACKTREE_GENERATOR_H

#include <ctime>
#include <iostream>
#include <unistd.h>

std::string gen_random(const int len) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}


#endif //REDBLACKTREE_GENERATOR_H
