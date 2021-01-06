
import java.util.ArrayList;

public class Mult extends Operador implements Observable {

    ArrayList<Observer> observadores = new ArrayList<>();

     Mult(Expression a, Expression b) {
    	this.filho1 = a;
    	this.filho2 = b;
    }

    public void registrar(Observer o) {
        observadores.add(o);
    }

    public double execute() {
	return filho1.execute() * filho2.execute();
     }

     public void notificarTodos() {
        for(Observer o: observadores)
            o.notificar(this);
    }

}
