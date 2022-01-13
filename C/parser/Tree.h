//
// Created by Цыпандин Николай Петрович on 20.12.2021.
//

#ifndef MATH_LOG_A_TREE_H
#define MATH_LOG_A_TREE_H

#include <string>
#include "../util/util.h"
#include "../string_util/string_util.h"
#include "../grammar/operation.h"

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

Tree *some_operation(operation op, Tree *left, Tree *right);

std::string tree_to_str(Tree *tree);

bool trees_equals(Tree *tree1, Tree *tree2);

#endif //MATH_LOG_A_TREE_H
