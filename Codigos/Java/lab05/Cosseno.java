

import static java.lang.Math.cos;


public class Cosseno extends ComponentDecorator {
    double valor = 0;

    public Cosseno(Expression compo) {
        super(compo);
        valor = compo.execute();
    }

    public double execute() {
        return cos(valor);
    }



}
