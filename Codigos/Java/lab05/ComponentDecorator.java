

public abstract class ComponentDecorator extends Expression {
    Expression componente;

    public ComponentDecorator(Expression compo) {
        componente = compo;
    }


}
