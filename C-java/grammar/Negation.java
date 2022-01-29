package grammar;

public class Negation extends Expression {

    public Negation() {
        this.operation = Op.NEGATION;
        this.value = operation.getStr();
    }

    public Negation(Expression left) {
        this.operation = Op.NEGATION;
        this.value = operation.getStr();
        this.left = left;
    }


    @Override
    public String buildStr() {
        return "(" + value + left.buildStr() + ")";
    }

    @Override
    public boolean equals(Object o) {
        if (this.getClass() != o.getClass())
            return false;
        Negation negation = (Negation) o;
        return this.left.equals(negation.left);
    }

    @Override
    public boolean solve() {
        return !(left.solve());
    }

    @Override
    public String toString() {
        return buildStr();
    }
}
