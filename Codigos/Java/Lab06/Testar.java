import java.util.*;

public class  Testar {
    private Collection c;
    private String[] vetor;
    private int tamVetor;

    public Testar(Collection c, String[] array) {
        this.c = c;
        this.vetor = array;
        for(Object s: array) {
           if(s != null)
              c.add(s);
        }

        contarVetorValido(array);
    }

    public void contarVetorValido(String[] array) {
        for(String a: array) {
            if(a != null)
                this.tamVetor++;
        }
    }

    public void verificar() {
        //Verificação de elementos duplicados
        System.out.println(c);
        System.out.println(tamVetor);
        if(c.size() == tamVetor)
            System.out.println("Permite elementos duplicados");
        else
            System.out.println("Não permite elementos duplicados");

        //Verificar se ordena automaticamente os elementos inseridos na coleção

        Object passado = null;
        boolean validar = false;
        int comp = 0; int ver = 0;
        for(Object o: c) {
            if(ver == 0) {
                passado = o;
                ver = 1;
            } else
                comp = ((String)o).compareTo((String)passado);
                System.out.println(comp);
                if(comp >= 0 && !validar) {
                    validar = false;
                } else
                    validar = true;

                passado = o;

        }

           if(!validar)
               System.out.println("Ordenado");
           else
               System.out.println("Não ordenado");


        //Garante a ordem de entrada dos elementos

        int cont = 0;
        boolean verificar = false;
        for(Object o : c) {

            if(vetor[cont] != null && !o.equals(vetor[cont])) {
                   verificar = true;
            }
            cont++;
        }

        //condicao para saber se ordena
        if(verificar)
            System.out.println("Não Garante Ordem");
        else
            System.out.println("Garante Ordem");
    }
}
