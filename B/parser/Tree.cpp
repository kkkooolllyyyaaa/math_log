//
// Created by Цыпандин Николай Петрович on 20.12.2021.
//

#include "Tree.h"

std::map<std::string, bool> temps;

Tree *some_tree(operation op, Tree *left, Tree *right, std::string value) {
    Tree *res = new Tree;
    res->op = op;
    res->left = left;
    res->right = right;
    res->value = std::move(value);
    return res;
}

std::string get_parsed(Tree *tree) {
    if (!tree->left)
        return tree->value;
    if (tree->op != NEGATION) {
        return "(" + get_op_str(tree->op).append(",").append(get_parsed(tree->left)).append(",").append(
                get_parsed(tree->right)).append(")");
    } else {
        return "(" + get_op_str(tree->op) + get_parsed(tree->left) + ")";
    }
}

void delete_tree(Tree *tree) {
    if (tree->left)
        delete_tree(tree->left);
    if (tree->right)
        delete_tree(tree->right);
    delete tree;
}

bool calculate_value(Tree *tree) {
    switch (tree->op) {
        case IMPLICATION:
            return implication(calculate_value(tree->left), calculate_value(tree->right));
        case DISJUNCTION:
            return calculate_value(tree->left) | calculate_value(tree->right);
        case CONJUNCTION:
            return calculate_value(tree->left) & calculate_value(tree->right);
        case NEGATION:
            return !(calculate_value(tree->left));
        case TEMP:
            return temps[tree->value];
        default:
            exit(1);
    }
}
