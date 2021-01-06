
public class Main {
	public static void main(String[] args) {

       Operando a = new Operando(2);
       Operando b = new Operando(3);

       //Criando observadores
       Observer o1 = new ObPositivo();
       Observer o2 = new ObZeroNegativo();


       Observable m = new Mult(a, b);

       m.registrar(o1);
       m.registrar(o2);

       ((Mult)m).notificarTodos();

       System.out.println(m.execute());

       Expression c1 = new Operando(3);
       Expression c2 = new Operando(3);

       c1 = new Seno(c1);
       c2 = new Cosseno(c2);

       Expression m2 = new Mult(c1, c2);

       System.out.println(m2.execute());

	}
}
