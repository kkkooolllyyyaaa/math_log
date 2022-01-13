//
// Created by Цыпандин Николай Петрович on 10.01.2022.
//

#ifndef MATH_LOG_A_DEDUCTION_PROCESSOR_H
#define MATH_LOG_A_DEDUCTION_PROCESSOR_H

#include <string>
#include <vector>
#include "../axiom/axiom.h"
#include "../parser/Tree.h"

bool is_hypothesis(Tree *candidate, const std::vector<Tree *>& hypotheses);

void theorem_split(const std::string &theorem_line, std::string *first, std::string *second);

void prove_alpha(Tree *alpha, std::vector<Tree *> *res);

void prove_hypothesis_or_axiom(Tree *alpha, Tree *sigma, std::vector<Tree *> *res);

void prove_modus_ponens(Tree *alpha, Tree *sigma_i,
                        Tree *sigma_j, std::vector<Tree *> *res);

#endif //MATH_LOG_A_DEDUCTION_PROCESSOR_H
