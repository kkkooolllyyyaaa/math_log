package grammar;

public enum Op {
    EXPRESSION("?"),
    IMPLICATION("->"),
    CONJUNCTION("&"),
    DISJUNCTION("|"),
    NEGATION("!"),
    CONSTANT("*");
    private final String str;

    Op(String str) {
        this.str = str;
    }

    public String getStr() {
        return str;
    }
}
