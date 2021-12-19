//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#ifndef MATH_LOG_A_STRING_UTIL_H
#define MATH_LOG_A_STRING_UTIL_H
#define ERROR_EXIT_CODE 1

#include <string>
#include <iostream>

std::string get_cleared(const std::string &input);

bool line_starts_with(const std::string &line, size_t pos, const std::string &target);

#endif //MATH_LOG_A_STRING_UTIL_H
