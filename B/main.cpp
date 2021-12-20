#include <iostream>
#include <string>
#include <vector>
#include "string_util/string_util.h"
#include "parser/parser.h"

using namespace std;
vector<bool> vs;

void vs_set(int x) {
    int cur = 1;
    for (int i = 0; i < vs.size(); ++i) {
        vs[i] = cur & x;
        cur *= 2;
    }
}

int main() {
    string input_line;
    getline(cin, input_line);
    state line = {.pos = 0, .data = get_cleared(input_line)};
    Tree *res = parse(&line);
    int variants = 1 << temps.size();
    int values_true = 0, values_false = 0;
    vs.resize(temps.size(), false);
    for (int i = 0; i < variants; ++i) {
        int cnt = 0;
        vs_set(i);
        for (auto &j: temps) {
            j.second = vs[cnt];
            ++cnt;
        }
        if (calculate_value(res))
            ++values_true;
        else
            ++values_false;
    }
    if (!values_true) {
        cout << "Unsatisfiable" << endl;
    } else if (!values_false) {
        cout << "Valid" << endl;
    } else {
        cout << "Satisfiable and invalid, " << values_true << " true and " << values_false << " false cases" << endl;
    }
    delete (res);
    return 0;
}
