public class Operando extends Expression {

    private float valor;

     Operando(float value) {
     	this.valor = value;
     }

	public double execute() {
		return valor;
	}

}
