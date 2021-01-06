public abstract class Figura {
    Ponto origem;
   //classe abstrata
	abstract void desenhar();

   //classe  concreta
   void mover(int dx, int dy) {
   	origem.setX(origem.getX()+dx);
   	origem.setY(origem.getY()+dy);
   }	

   abstract void calcularArea();
    
    
}
