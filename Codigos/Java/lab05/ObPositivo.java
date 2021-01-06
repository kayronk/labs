

public class ObPositivo implements Observer {
    public void notificar(Observable o) {
        double d = o.execute();
        if(d > 0)
           System.out.println("Valor da expressão é num numero positivo!!");

    }

}
