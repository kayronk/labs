package lab04;

public class ContaXPTOBasic extends Conta{
    public float credito;
    public float debito;

   
    public ContaXPTOBasic(float credito, float debito) {
        this.credito = credito;
        this.debito = debito;
    }
    
    public void creditar(float credito){
        this.setSaldo(this.getSaldo() + credito);
    }
            
    public void debitar(float debito){
        this.setSaldo(this.getSaldo() - debito);
    }
          
    public void consultar(){
        
    }

}
