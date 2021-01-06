
public class Main {
    public static void main(String[] args) {
    //questao 03
      Quadrado d1 = new Quadrado();
      Quadrado d2 = new Quadrado();

      //Ptestes dos dois quadrados


      d2.desenhar("verde");
      d1.setLado(3);
      d1.calcularArea();
      //d1.mover(1,1);


      Circulo cc1 = new Circulo();
      Circulo cc2 = new Circulo();

      //testes

      cc1.desenhar();
      cc1.setRaio(1);
      cc2.setRaio(2);
      cc1.calcularArea();
      cc2.calcularArea();

      //questao 05 criando um vetor de Figuras


      Figura figuras[] = new Figura[10];

      //figuras para armazenar

      Quadrado q1 = new Quadrado();
      Quadrado q2 = new Quadrado("blue");
      Quadrado q3 = new Quadrado("green");
      Quadrado q4 = new Quadrado();
      Quadrado q5 = new Quadrado();

      Circulo c1 = new Circulo("magenta");
      Circulo c2 = new Circulo();
      Circulo c3 = new Circulo("red");
      Circulo c4 = new Circulo("gray");
      Circulo c5 = new Circulo();

      //Preenchendo lados

      q1.setLado(1);
      q2.setLado(2);
      q3.setLado(3);
      q4.setLado(4);
      q5.setLado(5);

      c1.setRaio(1);
      c2.setRaio(2);
      c3.setRaio(3);
      c4.setRaio(4);
      c5.setRaio(5);

      //Preencendo vetor

      figuras[0] = q1;
      figuras[1] = q2;
      figuras[2] = q3;
      figuras[3] = q4;
      figuras[4] = q5;
      figuras[5] = c1;
      figuras[6] = c2;
      figuras[7] = c3;
      figuras[8] = c4;
      figuras[9] = c5;

      Quadrado aux;
      Circulo aux2;

      for(int i = 0; i < figuras.length; i++) {
           if(figuras[i] instanceof Quadrado) {
               aux = (Quadrado)figuras[i];
               if(aux.getTipo() == "Colorido") {
                  aux.calcularArea();
               }

           }else if(figuras[i] instanceof Circulo) {
               aux2 = (Circulo)figuras[i];
               if(aux2.getTipo() == "Colorido") {
                   aux2.calcularArea();
               }
           }
      }

    }
}
