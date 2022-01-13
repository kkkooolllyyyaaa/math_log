#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include "string_util/string_util.h"
#include "deduction_theorem/deduction_processor.h"
#include "axiom/axiom.h"
#include "parser/parser.h"

#define io_boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;

static vector<Tree *> ans;

static void print_ans(vector<Tree *> hypotheses, Tree *provable_new);

static void init_hypotheses(const string &hypotheses_line, vector<Tree *> *hypotheses);

int main() {
    io_boost;

    string input, hypotheses_line, provable_line;
    getline(cin, input);
    theorem_split(get_cleared(input), &hypotheses_line, &provable_line);
    hypotheses_line = hypotheses_line;
    provable_line = provable_line;
    Tree *provable = parse(provable_line);

    vector<Tree *> hypotheses;
    init_hypotheses(hypotheses_line, &hypotheses);
    Tree *alpha = hypotheses[hypotheses.size() - 1];
    Tree *provable_new = some_operation(IMPLICATION, alpha, provable);

    string proof_line;
    int N = 0;
    vector<Tree *> proofs;
    while (getline(cin, proof_line)) {
        if (proof_line == "EOF")
            break;
        Tree *proof = parse(get_cleared(proof_line));
        proofs.push_back(proof);
        ++N;
    }

    set<string> mp_bj;
    map<string, vector<Tree *>> mp_bk;

    for (int i = 0; i < N; ++i) {
        Tree *cur = proofs[i];
        string proof_str = tree_to_str(cur);

        if (trees_equals(alpha, cur))
            prove_alpha(alpha, &ans);

        else if (is_axiom(cur) != 0 || is_hypothesis(cur, hypotheses))
            prove_hypothesis_or_axiom(alpha, cur, &ans);

        else {
            vector<Tree *> sigma_j_found = mp_bk[proof_str];
            for (auto &sigma_j: sigma_j_found) {
                if (mp_bj.find(tree_to_str(sigma_j)) != mp_bj.end()) {
                    prove_modus_ponens(alpha, cur, sigma_j, &ans);
                    break;
                }
            }
        }
        if (cur->op == IMPLICATION) {
            mp_bk[tree_to_str(cur->right)].push_back(cur->left);
        }
        mp_bj.insert(proof_str);
    }

    print_ans(hypotheses, provable_new);
    return 0;
}

static void init_hypotheses(const string &hypotheses_line, vector<Tree *> *hypotheses) {
    string str;
    for (char i: hypotheses_line) {
        if (i == ',') {
            (*hypotheses).push_back(parse(get_cleared(str)));
            str = "";
        } else {
            str.push_back(i);
        }
    }
    if (!str.empty())
        (*hypotheses).push_back(parse(get_cleared(str)));
}

static void print_ans(vector<Tree *> hypotheses, Tree *provable_new) {
    if (hypotheses.size() > 1)
        cout << tree_to_str(hypotheses[0]);
    for (int i = 1; i < hypotheses.size() - 1; ++i) {
        cout << ',' << tree_to_str(hypotheses[i]);
    }

    cout << "|-" << tree_to_str(provable_new) << endl;

    for (int i = 0; i < ans.size() - 1; ++i) {
        cout << tree_to_str(ans[i]) << endl;
    }
    cout << tree_to_str(ans[ans.size() - 1]);
}
