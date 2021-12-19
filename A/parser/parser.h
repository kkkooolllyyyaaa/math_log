//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#ifndef MATH_LOG_A_PARSER_H
#define MATH_LOG_A_PARSER_H

#include <cstdlib>
#include <string>
#include "../string_util/string_util.h"
#include "../grammar/operation.h"
#include "../util/util.h"
#include "state.h"

std::string parse(state *line);

#endif //MATH_LOG_A_PARSER_H
