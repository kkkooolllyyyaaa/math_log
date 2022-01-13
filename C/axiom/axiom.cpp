//
// Created by Цыпандин Николай Петрович on 10.01.2022.
//

#include "axiom.h"

static bool is_axiom_1(Tree *tree) {
    return (
            tree->op == IMPLICATION &&
            tree->right->op == IMPLICATION &&
            trees_equals(tree->left, tree->right->right)
    );
}

Tree *get_axiom_1(Tree *a, Tree *b) {
    return some_operation(IMPLICATION,
                          a, some_operation(IMPLICATION,
                                            b, a
            )
    );
}

static bool is_axiom_2(Tree *tree) {
    return (
            tree->op == IMPLICATION &&
            tree->right->op == IMPLICATION &&
            tree->left->op == IMPLICATION &&
            tree->right->right->op == IMPLICATION &&
            tree->right->left->op == IMPLICATION &&
            tree->right->left->right->op == IMPLICATION &&
            trees_equals(tree->left->left, tree->right->right->left) &&
            trees_equals(tree->left->left, tree->right->left->left) &&
            trees_equals(tree->left->right, tree->right->left->right->left) &&
            trees_equals(tree->right->right->right, tree->right->left->right->right)
    );
}

Tree *get_axiom_2(Tree *a, Tree *b, Tree *c) {
    return some_operation(IMPLICATION,
                          some_operation(IMPLICATION, a, b),
                          some_operation(IMPLICATION,
                                         some_operation(IMPLICATION, a, some_operation(IMPLICATION, b, c)),
                                         some_operation(IMPLICATION, a, c)
                          )
    );
}

static bool is_axiom_3(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->right->op == IMPLICATION &&
            tree->right->right->op == CONJUNCTION &&
            trees_equals(tree->left, tree->right->right->left) &&
            trees_equals(tree->right->left, tree->right->right->right)
    );
}

static bool is_axiom_4(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->left->op == CONJUNCTION &&
            trees_equals(tree->right, tree->left->left)
    );
}

static bool is_axiom_5(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->left->op == CONJUNCTION &&
            trees_equals(tree->left->right, tree->right)
    );
}

static bool is_axiom_6(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->right->op == DISJUNCTION &&
            trees_equals(tree->left, tree->right->left)
    );
}

static bool is_axiom_7(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->right->op == DISJUNCTION &&
            trees_equals(tree->left, tree->right->right)
    );
}

static bool is_axiom_8(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->left->op == IMPLICATION &&
            tree->right->op == IMPLICATION &&
            tree->right->left->op == IMPLICATION &&
            tree->right->right->op == IMPLICATION &&
            tree->right->right->left->op == DISJUNCTION &&
            trees_equals(tree->left->left, tree->right->right->left->left) &&
            trees_equals(tree->left->right, tree->right->left->right) &&
            trees_equals(tree->left->right, tree->right->right->right) &&
            trees_equals(tree->right->left->left, tree->right->right->left->right)
    );
}

static bool is_axiom_9(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->left->op == IMPLICATION &&
            tree->right->op == IMPLICATION &&
            tree->right->left->op == IMPLICATION &&
            tree->right->left->right->op == NEGATION &&
            tree->right->right->op == NEGATION &&
            trees_equals(tree->left->left, tree->right->left->left) &&
            trees_equals(tree->left->left, tree->right->right->left) &&
            trees_equals(tree->left->right, tree->right->left->right->left)
    );
}

static bool is_axiom_10(Tree *tree) {
    return (tree->op == IMPLICATION &&
            tree->left->op == NEGATION &&
            tree->left->left->op == NEGATION &&
            trees_equals(tree->left->left->left, tree->right)
    );
}

int is_axiom(Tree *tree) {
    if (is_axiom_1(tree))
        return 1;
    if (is_axiom_2(tree))
        return 2;
    if (is_axiom_3(tree))
        return 3;
    if (is_axiom_4(tree))
        return 4;
    if (is_axiom_5(tree))
        return 5;
    if (is_axiom_6(tree))
        return 6;
    if (is_axiom_7(tree))
        return 7;
    if (is_axiom_8(tree))
        return 8;
    if (is_axiom_9(tree))
        return 9;
    if (is_axiom_10(tree))
        return 10;
    return 0;
}
