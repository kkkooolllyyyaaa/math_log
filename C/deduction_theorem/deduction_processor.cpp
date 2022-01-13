//
// Created by Цыпандин Николай Петрович on 10.01.2022.
//

#include "deduction_processor.h"

#include <utility>

static const enum operation impl = IMPLICATION;

bool is_hypothesis(Tree *candidate, const std::vector<Tree *> &hypotheses) {
    for (int i = 0; i < hypotheses.size() - 1; ++i) {
        if (trees_equals(candidate, hypotheses[i]))
            return true;
    }
    return false;
}

void theorem_split(const std::string &theorem_line, std::string *first, std::string *second) {
    size_t ind = theorem_line.find("|-");
    *first = theorem_line.substr(0, ind);
    *second = theorem_line.substr(ind + 2, theorem_line.length() - ind - 2);
}

void prove_alpha(Tree *alpha, std::vector<Tree *> *res) {
    (*res).push_back(
            get_axiom_1(alpha, alpha)
    );

    Tree *a_a = some_operation(impl, alpha, alpha);
    Tree *axiom2 = get_axiom_2(alpha, a_a, alpha);
    (*res).push_back(
            axiom2
    );

    (*res).push_back(
            axiom2->right
    );

    (*res).push_back(
            get_axiom_1(alpha, a_a)
    );

    (*res).push_back(a_a);
}

void prove_hypothesis_or_axiom(Tree *alpha, Tree *sigma, std::vector<Tree *> *res) {
    (*res).push_back(
            get_axiom_1(sigma, alpha)
    );

    (*res).push_back(sigma);

    Tree *a_s = some_operation(impl, alpha, sigma);
    (*res).push_back(a_s);
}

void prove_modus_ponens(Tree *alpha, Tree *sigma_i,
                        Tree *sigma_j, std::vector<Tree *> *res) {
    Tree *axiom2 = get_axiom_2(alpha, sigma_j, sigma_i);

    (*res).push_back(
            axiom2
    );
    (*res).push_back(
            axiom2->right
    );
    (*res).push_back(
            axiom2->right->right
    );
}
