//
// Created by Цыпандин Николай Петрович on 10.01.2022.
//

#ifndef MATH_LOG_A_AXIOM_H
#define MATH_LOG_A_AXIOM_H

#include "../parser/Tree.h"

int is_axiom(Tree *tree);

Tree *get_axiom_1(Tree *a, Tree *b);

Tree *get_axiom_2(Tree *a, Tree *b, Tree *c);

#endif //MATH_LOG_A_AXIOM_H
