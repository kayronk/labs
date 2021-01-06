import java.util.*;

public class Brasil {
    Map<String, String> estados = new HashMap<>();

    public  void inicializar(){

        estados.put("AC", "Acre");
        estados.put("AL", "Alagoas");
        estados.put("AP", "Amapa");
        estados.put("AM", "Amazonas");
        estados.put("BA", "Bahia");
        estados.put("CE", "Ceara");
        estados.put("DF", "Distrito Federal");
        estados.put("ES", "Espirito Santo");
        estados.put("GO", "Goais");
        estados.put("MA", "Maranhao");
        estados.put("MT", "Mato Grosso");
        estados.put("MS", "Mato Grosso Sul");
        estados.put("MG", "Minas Gerais");
        estados.put("PA", "Para");
        estados.put("PB", "Paraiba");
        estados.put("PR", "Parana");
        estados.put("PE", "Pernambuco");
        estados.put("PI", "Piaui");
        estados.put("RJ", "Rio de Janeiro");
        estados.put("RN", "Rio Grande do Norte");
        estados.put("RS", "Rio Grande do Sul");
        estados.put("RO", "Rondonia");
        estados.put("RR", "Roraima");
        estados.put("SC", "Santa Catarina");
        estados.put("SP", "Sao Paulo");
        estados.put("SE", "Sergipe");
        estados.put("TO", "Tocantins");
    }

    public void verificar(String s) {
        System.out.println(s+" -> "+estados.get(s));
    }
    public static void main(String[] args) {

        Brasil b = new Brasil();
        b.inicializar();
        b.verificar(args[0]);

    }
}
