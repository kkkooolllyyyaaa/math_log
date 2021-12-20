//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#ifndef MATH_LOG_A_OPERATION_H
#define MATH_LOG_A_OPERATION_H

#include <string>

typedef enum operation {
    IMPLICATION = 0,
    DISJUNCTION,
    CONJUNCTION,
    NEGATION,
    TEMP
} operation;

std::string get_op_str(operation op);

#endif //MATH_LOG_A_OPERATION_H
