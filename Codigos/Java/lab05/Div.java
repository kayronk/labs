public class Div extends Operador {

     Div(Expression a, Expression b) {
    	this.filho1 = a;
    	this.filho2 = b;
    }


	public double execute() {
		return filho1.execute() * filho2.execute();
	}
}
