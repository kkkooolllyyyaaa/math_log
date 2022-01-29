package grammar;

public class Implication extends Expression {

    public Implication() {
        this.operation = Op.IMPLICATION;
        this.value = operation.getStr();
    }

    public Implication(Expression left, Expression right) {
        this.operation = Op.IMPLICATION;
        this.value = operation.getStr();
        this.left = left;
        this.right = right;
    }

    @Override
    public String buildStr() {
        return "(" + left.buildStr() + this.value + right.buildStr() + ")";
    }

    @Override
    public boolean equals(Object o) {
        if (this.getClass() != o.getClass())
            return false;
        Implication implication = (Implication) o;
        return this.left.equals(implication.left) && this.right.equals(implication.right);
    }

    @Override
    public boolean solve() {
        boolean l = left.solve();
        if (!l)
            return true;
        return right.solve();
    }

    @Override
    public String toString() {
        return buildStr();
    }

}
