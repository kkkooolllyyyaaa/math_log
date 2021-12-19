#include <iostream>
#include <string>
#include "string_util/string_util.h"
#include "parser/parser.h"

using namespace std;

int main() {
    string input_line;
    getline(cin, input_line);
    state line = {.pos = 0, .data = get_cleared(input_line)};
    cout << parse(&line) << endl;
    return 0;
}
