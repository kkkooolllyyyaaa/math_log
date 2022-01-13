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
        default:
            return "*";
    }
}
