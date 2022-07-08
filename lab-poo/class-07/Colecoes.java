import java.util.*;

public class Colecoes {
  public static void main(String[] args) {
    List<String> nomes = new ArrayList<>();
    nomes.add("Maria");
    nomes.add("Ana");
    nomes.add("José");

    Integer[] numerosArray = { 9, 3, 2 };
    List<Integer> numeros = Arrays.asList(numerosArray);

    System.out.println("====> Lista Nomes Desordenada");
    System.out.println(nomes + "\n");

    System.out.println("====> Lista Números Desordenada");
    System.out.println(numeros + "\n");

    Collections.sort(nomes, Collections.reverseOrder());
    Collections.sort(numeros);

    System.out.println("====> Lista Nomes Ordenada");
    System.out.println(nomes + "\n");

    System.out.println("====> Lista Números Ordenada");
    System.out.println(numeros + "\n");
  }
}