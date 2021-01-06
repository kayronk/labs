package lab04;

public abstract class Conta extends Sistema{
    private int id;
    private int TipoDaConta;
    private float Saldo; 

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getTipoDaConta() {
        return TipoDaConta;
    }

    public void setTipoDaConta(int TipoDaConta) {
        this.TipoDaConta = TipoDaConta;
    }

    public float getSaldo() {
        return Saldo;
    }

    public void setSaldo(float Saldo) {
        this.Saldo = Saldo;
    }
    
    
}
