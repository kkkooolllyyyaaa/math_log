//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#ifndef MATH_LOG_A_OPERATION_H
#define MATH_LOG_A_OPERATION_H
#define ERROR_EXIT_CODE 1

#include <iostream>
#include <string>
#include "../string_util/string_util.h"
#include "../util/util.h"

typedef enum operation {
    IMPLICATION = 0,
    DISJUNCTION,
    CONJUNCTION,
    NEGATION,
    BRACKET_LEFT,
    BRACKET_RIGHT,
    TEMP,
    ERROR
} operation;

std::string get_op_str(operation op);

operation get_op_enum(char c);

#endif //MATH_LOG_A_OPERATION_H
