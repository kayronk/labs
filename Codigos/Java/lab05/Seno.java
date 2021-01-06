
import static java.lang.Math.sin;


public class Seno extends ComponentDecorator {
    double valor = 0;

    public Seno(Expression compo) {
        super(compo);
        valor = compo.execute();
    }


   public double execute() {
     return sin(valor);
    }

}
