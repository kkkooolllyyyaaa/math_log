//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#include "parser.h"

static std::string get_binary(std::string op, const std::string &left, const std::string &right);

static std::string get_unary(std::string op, const std::string &left);

static std::string expression(state *line);

static std::string dis(state *line);

static std::string con(state *line);

static std::string neg(state *line);

std::string parse(state *line) {
    return expression(line);
}

static std::string get_binary(std::string op, const std::string &left, const std::string &right) {
    return "(" + op.append(",").append(left).append(",").append(right).append(")");
}

static std::string get_unary(std::string op, const std::string &left) {
    return "(" + op.append(left).append(")");
}

static std::string expression(state *line) {
    std::string left = dis(line);
    std::string op = get_op_str(IMPLICATION);
    while (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        std::string right = expression(line);
        left = get_binary(op, left, right);
    }
    return left;
}

static std::string dis(state *line) {
    std::string left = con(line);
    std::string op = get_op_str(DISJUNCTION);
    while (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        std::string right = con(line);
        left = get_binary(op, left, right);
    }
    return left;
}

static std::string con(state *line) {
    std::string left = neg(line);
    std::string op = get_op_str(CONJUNCTION);
    while (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        std::string right = neg(line);
        left = get_binary(op, left, right);
    }
    return left;
}

static std::string neg(state *line) {
    std::string left;
    std::string op = get_op_str(NEGATION);
    if (line_starts_with(line->data, line->pos, "(")) {
        line->pos++;                                                // first bracket
        left = expression(line);
        line->pos++;                                                // second bracket
    } else if (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        left = get_unary(op, neg(line));
    } else if (is_temp_symbol(line->data[line->pos])) {
        left = get_temp(line);
    }
    return left;
}
