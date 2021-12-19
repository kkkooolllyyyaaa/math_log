//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#include "string_util.h"

static bool is_space_symbol(char c) {
    return c == '\n' || c == '\r' || c == '\t' || c == ' ' || c == '\v' || c == '\f';
}

std::string get_cleared(const std::string &input) {
    std::string res;
    for(size_t i = 0;i<input.length();++i){
        if(!is_space_symbol(input[i]))
            res.push_back(input[i]);
    }
    return res;
}

bool line_starts_with(const std::string &line, size_t pos, const std::string &target) {
    if (target.length() > (line.length() - pos))
        return false;
    for (size_t i = 0; i < target.length(); ++i) {
        if (line[i + pos] != target[i])
            return false;
    }
    return true;
}
