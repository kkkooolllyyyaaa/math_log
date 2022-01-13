//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#include "string_util.h"

static bool is_space_symbol(char c) {
    return c == '\n' || c == '\r' || c == '\t' || c == ' ' || c == '\v' || c == '\f';
}

std::string get_cleared(const std::string &input) {
    std::string res;
    for (char i: input)
        if (!is_space_symbol(i))
            res.push_back(i);
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

std::string bracket(const std::string &line) {
    return "(" + line + ")";
}

bool str_equals(std::string s1, std::string s2) {
    if (s1.length() != s2.length())
        return false;
    for (int i = 0; i < s1.length(); ++i) {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}
