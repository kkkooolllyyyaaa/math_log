//
// Created by Цыпандин Николай Петрович on 19.12.2021.
//

#ifndef MATH_LOG_A_PARSER_H
#define MATH_LOG_A_PARSER_H

#include <string>
#include "../grammar/operation.h"
#include "../string_util/string_util.h"
#include "../util/util.h"
#include "Tree.h"
#include "state.h"

Tree *parse(std::string line);

#endif //MATH_LOG_A_PARSER_H
