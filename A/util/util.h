//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#ifndef MATH_LOG_A_UTIL_H
#define MATH_LOG_A_UTIL_H

#include <string>
#include "../parser/state.h"

bool is_in_alphabet(char c);

bool is_temp_symbol(char c);

std::string get_temp(state* line);

#endif //MATH_LOG_A_UTIL_H
