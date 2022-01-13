//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#include "util.h"

bool is_temp_symbol(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || (c == 39);
}

std::string get_temp(state *line) {
    std::string temp;
    while (is_temp_symbol(line->data[line->pos])) {
        temp.push_back(line->data[line->pos++]);
    }
    return temp;
}
