public class OperatorPriority {
    public static void main(String[] a) {
        System.out.println(new OP().arithmetic());
    }
}

class OP {

    public boolean relational() {
        int a;
        int b;
        boolean c;
        boolean d;
        a = 10;
        b = 12;
        d = false;
        c = true;
        boolean ret;
        // the following statements should generate the same tree
        ret = a < b && !d || d == !c;
        ret = ((a < b) && (!d)) || (d == (!c));
        return ret;
    }
}
