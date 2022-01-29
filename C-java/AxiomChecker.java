import grammar.Expression;
import grammar.Implication;
import grammar.Op;

public class AxiomChecker {

    static boolean isAxiom(Expression tree) {
        if (axiom1(tree))
            return true;
        if (axiom2(tree))
            return true;
        if (axiom3(tree))
            return true;
        if (axiom4(tree))
            return true;
        if (axiom5(tree))
            return true;
        if (axiom6(tree))
            return true;
        if (axiom7(tree))
            return true;
        if (axiom8(tree))
            return true;
        if (axiom9(tree))
            return true;
        return axiom10(tree);
    }

    static Expression getAxiom1(Expression expr1, Expression expr2) {
        return new Implication(expr1, new Implication(expr2, expr1));
    }

    static Expression getAxiom2(Expression expr1, Expression expr2, Expression expr3) {
        return new Implication(new Implication(expr1, expr2),
                new Implication(new Implication(expr1,
                        new Implication(expr2, expr3)),
                        new Implication(expr1, expr3)));
    }

    private static boolean axiom1(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.right.operation == Op.IMPLICATION &&
                expr.left.equals(expr.right.right)
        );
    }


    private static boolean axiom2(Expression expr) {
        return (
                expr.operation == Op.IMPLICATION &&
                        expr.right.operation == Op.IMPLICATION &&
                        expr.left.operation == Op.IMPLICATION &&
                        expr.right.right.operation == Op.IMPLICATION &&
                        expr.right.left.operation == Op.IMPLICATION &&
                        expr.right.left.right.operation == Op.IMPLICATION &&
                        expr.left.left.equals(expr.right.right.left) &&
                        expr.left.left.equals(expr.right.left.left) &&
                        expr.left.right.equals(expr.right.left.right.left) &&
                        expr.right.right.right.equals(expr.right.left.right.right)
        );
    }

    private static boolean axiom3(Expression expr) {

        return (expr.operation == Op.IMPLICATION &&
                expr.right.operation == Op.IMPLICATION &&
                expr.right.right.operation == Op.CONJUNCTION &&
                expr.left.equals(expr.right.right.left) &&
                expr.right.left.equals(expr.right.right.right)

        );
    }

    private static boolean axiom4(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.left.operation == Op.CONJUNCTION &&
                expr.right.equals(expr.left.left)
        );
    }

    private static boolean axiom5(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.left.operation == Op.CONJUNCTION &&
                expr.right.equals(expr.left.right)
        );
    }

    private static boolean axiom6(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.right.operation == Op.DISJUNCTION &&
                expr.left.equals(expr.right.left)
        );
    }

    private static boolean axiom7(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.right.operation == Op.DISJUNCTION &&
                expr.left.equals(expr.right.right)
        );
    }

    private static boolean axiom8(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.left.operation == Op.IMPLICATION &&
                expr.right.operation == Op.IMPLICATION &&
                expr.right.left.operation == Op.IMPLICATION &&
                expr.right.right.operation == Op.IMPLICATION &&
                expr.right.right.left.operation == Op.DISJUNCTION &&
                expr.left.left.equals(expr.right.right.left.left) &&
                expr.left.right.equals(expr.right.left.right) &&
                expr.left.right.equals(expr.right.right.right) &&
                expr.right.left.left.equals(expr.right.right.left.right)
        );
    }

    private static boolean axiom9(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.left.operation == Op.IMPLICATION &&
                expr.right.operation == Op.IMPLICATION &&
                expr.right.left.operation == Op.IMPLICATION &&
                expr.right.left.right.operation == Op.NEGATION &&
                expr.right.right.operation == Op.NEGATION &&
                expr.left.left.equals(expr.right.left.left) &&
                expr.left.left.equals(expr.right.right.left) &&
                expr.left.right.equals(expr.right.left.right.left)
        );
    }

    private static boolean axiom10(Expression expr) {
        return (expr.operation == Op.IMPLICATION &&
                expr.left.operation == Op.NEGATION &&
                expr.left.left.operation == Op.NEGATION &&
                expr.left.left.left.equals(expr.right)
        );
    }

}
