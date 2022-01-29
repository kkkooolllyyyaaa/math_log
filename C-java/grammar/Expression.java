package grammar;

public abstract class Expression {
    public Expression left;
    public Expression right;
    public String value;
    public Op operation;

    public abstract String buildStr();

    public abstract boolean equals(Object o);

    public abstract boolean solve();
}
