package lab04;

public class ContaXPTOPlus extends Conta{
    public float credito;
    public float debito;

   
    public ContaXPTOPlus(float credito, float debito) {
        this.credito = credito;
        this.debito = debito;
    }
    
    public void creditar(float credito){
        this.setSaldo(this.getSaldo() + (credito*1.05f));
    }
            
    public void debitar(float debito){
        this.setSaldo(this.getSaldo() - debito);
    }
          
    public void consultar(){
        
    }

}
