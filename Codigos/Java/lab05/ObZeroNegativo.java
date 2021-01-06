
//classe zero ou negativo implementando o observer da questão 03


public class ObZeroNegativo implements Observer {
    public void notificar(Observable o) {
        double d = o.execute();
        if(d == 0)
            System.out.println("Valor da expressão é zero");
        if(d < 0)
            System.out.println("Valor da expressão é um numero negativo");
    }

}
