//
// Created by Цыпандин Николай Петрович on 20.12.2021.
//

#ifndef MATH_LOG_A_TREE_H
#define MATH_LOG_A_TREE_H

#include <string>
#include <map>
#include "../util/util.h"
#include "../grammar/operation.h"

extern std::map<std::string, bool> temps;

struct Tree {
    operation op;
    Tree *left;
    Tree *right;
    std::string value;

    ~Tree() {
        delete left;
        delete right;
    }
};


Tree *some_tree(operation op, Tree *left, Tree *right, std::string value);

std::string get_parsed(Tree *tree);

bool calculate_value(Tree *tree);

#endif //MATH_LOG_A_TREE_H
