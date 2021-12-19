//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#include "operation.h"

std::string get_op_str(const operation op) {
    switch (op) {
        case IMPLICATION:
            return "->";
        case DISJUNCTION:
            return "|";
        case CONJUNCTION:
            return "&";
        case NEGATION:
            return "!";
        case BRACKET_LEFT:
            return "(";
        case BRACKET_RIGHT:
            return ")";
        case TEMP:
            return "*";
        default:
            std::cerr << "Unexpected operation\n";
            exit(ERROR_EXIT_CODE);
    }
}

operation get_op_enum(char c) {
    if (!is_in_alphabet(c))
        return ERROR;
    switch (c) {
        case '-':
            return IMPLICATION;
        case '|':
            return DISJUNCTION;
        case '&':
            return CONJUNCTION;
        case '!':
            return NEGATION;
        case '(':
            return BRACKET_LEFT;
        case ')':
            return BRACKET_RIGHT;
        default:
            return TEMP;
    }
}
