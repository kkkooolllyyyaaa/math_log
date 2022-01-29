import grammar.Expression;
import grammar.Implication;
import grammar.Op;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Main {
    static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

    static String clear(String str) {
        String cleared = "";
        for (int i = 0; i < str.length(); ++i) {
            char cur = str.charAt(i);
            if (cur == '\n' || cur == '\r' || cur == '\t' || cur == ' ') {
            } else
                cleared = cleared + cur;
        }
        return cleared;
    }

    static boolean isHypothesis(Expression expression, ArrayList<Expression> hypotheses) {
        for (int i = 0; i < hypotheses.size() - 1; ++i) {
            if (expression.equals(hypotheses.get(i)))
                return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        String input = clear(reader.readLine());
        String[] leftRight = input.split("\\|-");
        String[] hypothesesStr = leftRight[0].split(",");
        ArrayList<Expression> hypotheses = new ArrayList<>();
        for (String s : hypothesesStr)
            hypotheses.add(ExpressionParser.parse(s));
        Expression alpha = hypotheses.get(hypotheses.size() - 1);


        String proof = leftRight[1];
        Expression proofNew = new Implication(alpha, ExpressionParser.parse(proof));


        ArrayList<Expression> proofLines = new ArrayList<>();
        while ((input = reader.readLine()) != null) {
            if (input.equals("EOF"))
                break;
            proofLines.add(ExpressionParser.parse(clear(input)));
        }

        ArrayList<Expression> ans = new ArrayList<>();
        HashMap<String, ArrayList<Expression>> bk = new HashMap<>();
        HashSet<String> bj = new HashSet<>();
        for (Expression expr : proofLines) {
            String exprStr = expr.buildStr();
            if (alpha.equals(expr)) {

                ans.add(AxiomChecker.getAxiom1(alpha, alpha));
                Expression aa = new Implication(alpha, alpha);
                Expression axiom2 = AxiomChecker.getAxiom2(alpha, aa, alpha);
                ans.add(axiom2);
                ans.add(axiom2.right);
                ans.add(AxiomChecker.getAxiom1(alpha, aa));
                ans.add(aa);

            } else if (AxiomChecker.isAxiom(expr) || isHypothesis(expr, hypotheses)) {

                ans.add(AxiomChecker.getAxiom1(expr, alpha));
                ans.add(expr);
                ans.add(new Implication(alpha, expr));


            } else {
                ArrayList<Expression> expressions = bk.get(exprStr);
                for (Expression e : expressions) {
                    if (bj.contains(e.buildStr())) {
                        Expression axiom2 = AxiomChecker.getAxiom2(alpha, e, expr);
                        ans.add(axiom2);
                        ans.add(axiom2.right);
                        ans.add(axiom2.right.right);
                        break;
                    }
                }
            }
            if (expr.operation == Op.IMPLICATION) {
                String rightStr = expr.right.buildStr();
                bk.computeIfAbsent(rightStr, k -> new ArrayList<>());
                bk.get(rightStr).add(expr.left);
            }
            bj.add(exprStr);
        }


        if (hypotheses.size() > 1)
            System.out.print(hypotheses.get(0).buildStr());
        for (int i = 1; i < hypotheses.size() - 1; ++i) {
            System.out.print("," + hypotheses.get(i).buildStr());
        }
        System.out.println("|-" + proofNew.buildStr());
        for (int i = 0; i < ans.size(); ++i) {
            System.out.println(ans.get(i).buildStr());
        }
    }
}
