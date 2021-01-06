class Conjunto {
    static final int MAX = 10;

    private int matrix[][];
    private int elementos[];
    private boolean vazio = true;
    private int ordem;

    public Conjunto(){
       this.vazio = true;
    }


    //Construtor que recebe um conjunto já predefinido
    public Conjunto(int elementos[]) {
        this.elementos = elementos;
        this.vazio = false;
    }


    //Criar conjunto. com tamanho passado por parametro
    public Conjunto(int tam) {
        this.elementos = new int[tam];
    }

    //Criar uma matrix no conjunto
    public Conjunto(int a, int b) {
    	this.matrix = new int[a][b];
    }


    public void insercao(int a) {
        this.elementos[ordem] = a;
        this.ordem++;
        this.vazio = false;

     }

    public void inserir_matrix(int a, int b) {
    	this.matrix[ordem][0] = a ;
    	this.matrix[ordem][1] = b;
    	this.ordem++;
    	this.vazio = false;
    }
    //Pertinencia de um elemento a um conjunto
    public boolean pertinencia(int a) {
      for (int i = 0; i < this.elementos.length ;i++ ) {
        if (this.elementos[i] == a)
            return true;
       }

       return false;
    }

    //Pertinencia de um conjunto em outro conjunto

    public boolean pertinencia_conjunto(Conjunto conj) {
      return true;
    }

    public boolean subconjunto(Conjunto conj){
      boolean verificador = false;
      int ver = 0;
      for(int i = 0; i < conj.elementos.length; i++) {
        for (int j = 0; j < elementos.length ;j++) {
         if (conj.elementos[i] != 0) {

          if(conj.elementos[i] == this.elementos[j] && ver == 0) {
              verificador = true;
              ver = 1;
          }

          else if (ver == 0) {
              verificador = false;
           }
          }
        }
        ver = 0;
      }

      return verificador;

    }


   public Conjunto uniao(Conjunto conj) {

    //-----------------------------
      boolean verificador = true;
      int cont = 0;
    for (int i = 0;i < conj.elementos.length ;i++ ) {
      for (int j = 0;j < elementos.length ;j++ ) {
        if (conj.elementos[i] == elementos[j]) {
           verificador =  false;
        }
      }
      if (verificador) {
        cont++;
      }
      verificador = true;
    }

    cont = cont + elementos.length;

    Conjunto uni = new Conjunto(cont);

    //------------------------

      for (int i = 0;i < conj.elementos.length ;i++ ) {
       for (int j = 0;j < elementos.length ;j++ ) {
         if (conj.elementos[i] == elementos[j]) {
            verificador =  false;
         }
       }
       if (verificador) {
         uni.insercao(conj.elementos[i] ) ;
       }
       verificador = true;
     }

     for (int i = 0 ; i < elementos.length ;i++ ) {
         uni.insercao(elementos[i]);
     }

    return uni;

   }


   //Modificar
   public Conjunto interseccao(Conjunto conj){


    //contador para saber quantos elementos tem insercao
	   int cont = 0;

	for(int i = 0; i < conj.elementos.length; i++) {
		for(int j = 0 ; j < elementos.length; j++) {
			if(conj.elementos[i] == this.elementos[j] && conj.elementos[i] != 0) {
				cont++;
			}
		}
	}
   Conjunto inter = new Conjunto(cont);

    for (int i = 0; i < conj.elementos.length;i++ ) {
      for (int j = 0; j < elementos.length;j++ ) {
        if(conj.elementos[i] == this.elementos[j] && conj.elementos[i] != 0) {
          inter.insercao(conj.elementos[i]);
        }

      }
    }

    return inter;

   }

    public Conjunto diferenca(Conjunto conj) {

      Conjunto dif = new Conjunto(elementos.length-conj.elementos.length);
      boolean verificador = false;
      for (int i = 0 ;i < elementos.length ;i++ ) {
        for (int j = 0;j < conj.elementos.length ;j++ ) {
          if(elementos[i] == conj.elementos[j] && verificador == false ) {
            verificador = true;
          }
        }
      if(!verificador) {
        dif.insercao(elementos[i]);
      }
      verificador = false;
      }

      return dif;

    }


   //---------------------------

    public void Print() {
      for(int i=0; i < elementos.length; i++)
        System.out.println(elementos[i]);
    }

    public void Print_Matrix() {
    	int j = 0;
    	for(int i = 0; i < this.ordem; i++) {

    	System.out.println("{"+matrix[i][j]+", "+matrix[i][j+1]+"}");
    	j = 0;

    	}
    }

    public boolean getVazio() {
      return this.vazio;
    }


    // Q04
    //Primeiro teste apenas imprimindo o valor
    public void pro_cartesiano(Conjunto conj) {

    	for(int i = 0; i < elementos.length; i++) {
    		for(int j = 0; j < conj.elementos.length;j++) {
    			System.out.println("{"+elementos[i]+", "+conj.elementos[j]+"} ");
    		}
    	}

    }



    public Conjunto produto_cartesiano(Conjunto conj) {

    	int tam = elementos.length*conj.elementos.length;
    	Conjunto c3 = new Conjunto(tam, tam);

    	for(int i = 0; i < elementos.length; i++ ) {
    		for(int j = 0; j < conj.elementos.length; j++) {
    		    c3.inserir_matrix(elementos[i], conj.elementos[j]);
    		}
    	}

    	return c3;

    }

}
