
//classe hash 2 da segunda questao
import java.util.*;

class Teste_Hash2 {

 public static void listar(Collection c) {
     Iterator it = c.iterator();

     while(it.hasNext()) {
       System.out.println(it.next());
     }
 }

 public static void listar2(Collection c) {
    System.out.println("*** Listar 2 ****");
    for(Object o: c)
        System.out.println(o);
 }

 public static void main(String args[]){

      Set<String> mesesHash = new LinkedHashSet<>();

      mesesHash.add("Janeiro");
      mesesHash.add("Fevereiro");
      mesesHash.add("Março");
      mesesHash.add("Abril");
      mesesHash.add("Maio");
      mesesHash.add("Fevereiro");

      System.out.println("HashSet:");
      Teste_Hash2.listar(mesesHash);
      Teste_Hash2.listar2(mesesHash);
 }
}
