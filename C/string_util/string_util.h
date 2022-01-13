//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#ifndef MATH_LOG_A_STRING_UTIL_H
#define MATH_LOG_A_STRING_UTIL_H

#include <string>
#include <vector>

std::string get_cleared(const std::string &input);

bool line_starts_with(const std::string &line, size_t pos, const std::string &target);

std::string bracket(const std::string &line);

bool str_equals(std::string s1, std::string s2);

#endif //MATH_LOG_A_STRING_UTIL_H
