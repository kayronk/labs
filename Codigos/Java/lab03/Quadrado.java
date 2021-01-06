
public class Quadrado extends Figura implements FiguraColorida  {
    	private Ponto a, b, c, d;
	private float lado;
        private String tipo = "não colorido";
        private String cor;

        //metodo Construtor
        Quadrado() {}
        Quadrado(String cor) {
            this.tipo = "Colorido";
            this.cor = cor;
        }


	public String toString() {
		return "Quadrado, "+this.tipo ;
	}

	 public void desenhar() {

		System.out.println(this.toString());
	}

         public void desenhar(String cor) {
             this.tipo = "Colorido";
             this.cor = cor;
             System.out.println(this.toString());
         }

	void calcularLado() {

	}

    public void calcularArea() {
         System.out.println("Area é: "+lado*lado);
    }

    //Metodos sets e gets

    public void setLado(float lado) {
    	this.lado = lado;
    }

    public float getLado() {
    	return this.lado;
    }

    public String getTipo() {
        return this.tipo;
    }

    public String getCor() {
        return cor;
    }
}
