//
// Created by Цыпандин Николай Петрович on 20.12.2021.
//

#include "Tree.h"

Tree *some_tree(operation op, Tree *left, Tree *right, std::string value) {
    Tree *res = new Tree;
    res->op = op;
    res->left = left;
    res->right = right;
    res->value = std::move(value);
    return res;
}

Tree *some_operation(operation op, Tree *left, Tree *right) {
    Tree *res = new Tree;
    res->op = op;
    res->left = left;
    res->right = right;
    res->value = get_op_str(op);
    return res;
}

std::string tree_to_str(Tree *tree) {
    if (tree->op == TEMP)
        return tree->value;
    if (tree->op == NEGATION)
        return bracket("!" + tree_to_str(tree->left));
    return bracket(tree_to_str(tree->left) + get_op_str(tree->op) + tree_to_str(tree->right));
}

bool trees_equals(Tree *tree1, Tree *tree2) {
    if (!tree1 || !tree2)
        return false;
    if (tree1->op == tree2->op) {
        if (tree1->op == TEMP)
            return str_equals(tree1->value, tree2->value);
        else if (tree1->op == NEGATION)
            return trees_equals(tree1->left, tree2->left);
        else
            return trees_equals(tree1->left, tree2->left) && trees_equals(tree1->right, tree2->right);
    }
    return false;
}
