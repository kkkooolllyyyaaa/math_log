import grammar.*;

public class ExpressionParser {
    private static int position;
    private static String line;

    static Expression parse(String line) {
        ExpressionParser.line = line;
        position = 0;
        return expression();
    }

    private static boolean constant_char(char c) {
        return (c >= 65 && c <= 90) || (c >= 48 && c <= 57) || (c == 39);
    }

    private static String getConstantStr() {
        StringBuilder constant = new StringBuilder();
        while (position < line.length() && constant_char(line.charAt(position))) {
            constant.append(line.charAt(position));
            position = position + 1;
        }
        return constant.toString();
    }

    private static Expression expression() {
        Expression left = dis();

        String op = Op.IMPLICATION.getStr();
        while (line.substring(position).startsWith(op)) {
            position = position + op.length();
            Expression right = expression();
            left = new Implication(left, right);
        }
        return left;
    }

    private static Expression dis() {
        Expression left = con();

        String op = Op.DISJUNCTION.getStr();
        while (line.substring(position).startsWith(op)) {
            position = position + op.length();
            Expression right = con();
            left = new Disjunction(left, right);
        }
        return left;
    }

    private static Expression con() {
        Expression left = neg();

        String op = Op.CONJUNCTION.getStr();
        while (line.substring(position).startsWith(op)) {
            position = position + op.length();
            Expression right = neg();
            left = new Conjunction(left, right);
        }
        return left;
    }

    private static Expression neg() {
        String op = Op.NEGATION.getStr();
        if (line.substring(position).startsWith("(")) {
            position = position + 1;
            Expression left = expression();
            position = position + 1;
            return left;
        } else if (line.substring(position).startsWith(op)) {
            position = position + op.length();
            Expression left = neg();
            return new Negation(left);
        } else if (constant_char(line.charAt(position))) {
            String val = getConstantStr();
            return new Constant(val);
        }
        return null;
    }
}
