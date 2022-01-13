//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#include "parser.h"

#include <utility>

static Tree *expression(state *line);

static Tree *dis(state *line);

static Tree *con(state *line);

static Tree *neg(state *line);

Tree *parse(std::string line) {
    state st = {.pos = 0, .data = std::move(line)};
    return expression(&st);
}

static Tree *expression(state *line) {
    std::string op = get_op_str(IMPLICATION);
    Tree *left = dis(line);

    while (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        Tree *right = expression(line);
        left = some_operation(IMPLICATION, left, right);
    }
    return left;
}

static Tree *dis(state *line) {
    std::string op = get_op_str(DISJUNCTION);
    Tree *left = con(line);

    while (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        Tree *right = con(line);
        left = some_operation(DISJUNCTION, left, right);
    }
    return left;
}

static Tree *con(state *line) {
    std::string op = get_op_str(CONJUNCTION);
    Tree *left = neg(line);

    while (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        Tree *right = neg(line);
        left = some_operation(CONJUNCTION, left, right);
    }
    return left;
}

static Tree *neg(state *line) {
    std::string op = get_op_str(NEGATION);
    if (line_starts_with(line->data, line->pos, "(")) {
        line->pos++;
        Tree *left = expression(line);
        line->pos++;
        return left;
    } else if (line_starts_with(line->data, line->pos, op)) {
        line->pos += op.length();
        Tree *left = neg(line);
        return some_operation(NEGATION, left, nullptr);
    } else if (is_temp_symbol(line->data[line->pos])) {
        std::string val = get_temp(line);
        return some_tree(TEMP, nullptr, nullptr, val);
    }
    return nullptr;
}
