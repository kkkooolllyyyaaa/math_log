package grammar;

public class Conjunction extends Expression {

    public Conjunction() {
        this.operation = Op.CONJUNCTION;
        this.value = operation.getStr();
    }

    public Conjunction(Expression left, Expression right) {
        this.operation = Op.CONJUNCTION;
        this.value = operation.getStr();
        this.left = left;
        this.right = right;
    }

    @Override
    public String buildStr() {
        return "(" + left.buildStr() + value + right.buildStr() + ")";
    }

    @Override
    public boolean equals(Object o) {
        if (this.getClass() != o.getClass())
            return false;
        Conjunction conjunction = (Conjunction) o;
        return this.left.equals(conjunction.left) && this.right.equals(conjunction.right);
    }

    @Override
    public boolean solve() {
        return left.solve() && right.solve();
    }

    @Override
    public String toString() {
        return buildStr();
    }
}
