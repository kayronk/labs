package lab04;

public class ContaXPTOExtreme extends Conta{
    public float credito;
    public float debito;

    public ContaXPTOExtreme(float credito, float debito) {
        this.credito = credito;
        this.debito = debito;
    }
    
    public void creditar(float credito){
        this.setSaldo(this.getSaldo() + (credito*1.02f));
    }
            
    public void debitar(float debito){
        this.setSaldo(this.getSaldo() - (debito*0.98f));
    }
          
    public void consultar(){
        
    }

}