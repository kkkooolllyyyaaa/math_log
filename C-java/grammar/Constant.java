package grammar;

public class Constant extends Expression {
    public boolean logicValue = false;

    public Constant(String value) {
        this.value = value;
        this.operation = Op.CONSTANT;
    }

    @Override
    public String buildStr() {
        return value;
    }

    @Override
    public boolean equals(Object o) {
        if (this.getClass() != o.getClass())
            return false;
        Constant constant = (Constant) o;
        return this.value.equals(constant.value);
    }

    @Override
    public boolean solve() {
        return logicValue;
    }

    @Override
    public String toString() {
        return buildStr();
    }
}
