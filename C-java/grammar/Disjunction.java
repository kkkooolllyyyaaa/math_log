package grammar;

public class Disjunction extends Expression {

    public Disjunction() {
        this.operation = Op.DISJUNCTION;
        this.value = operation.getStr();
    }

    public Disjunction(Expression left, Expression right) {
        this.operation = Op.DISJUNCTION;
        this.value = operation.getStr();
        this.left = left;
        this.right = right;
    }

    @Override
    public String buildStr() {
        return "("+left.buildStr() + value + right.buildStr()+")";
    }

    @Override
    public boolean equals(Object o) {
        if (this.getClass() != o.getClass())
            return false;
        Disjunction disjunction = (Disjunction) o;
        return this.left.equals(disjunction.left) && this.right.equals(disjunction.right);
    }

    @Override
    public boolean solve() {
        return left.solve() || right.solve();
    }

    @Override
    public String toString() {
        return buildStr();
    }
}
