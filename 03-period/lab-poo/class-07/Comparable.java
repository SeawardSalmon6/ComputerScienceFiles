import java.util.*;

public class Comparable {
  public static void main(String[] args) {
    List<Pessoa> pessoas = new ArrayList<>();
    Pessoa joao = new Pessoa("João", 20, 2983.23);
    Pessoa maria = new Pessoa("Maria", 43, 2343.32);
    Pessoa zenaide = new Pessoa("Zenaide", 18, 1500);

    pessoas.add(joao);
    pessoas.add(maria);
    pessoas.add(zenaide);

    System.out.println("========== Lista Completa");
    for (Pessoa p : pessoas) {
      System.out.println("Nome: " + p.getNome());
      System.out.println("Idade: " + p.getIdade());
      System.out.println("Salário: " + p.getSalario() + "\n");
    }

    System.out.println("========== Lista Ordenada");
    Collections.sort(pessoas, Collections.reverseOrder());

    for (Pessoa p : pessoas) {
      System.out.println("Nome: " + p.getNome());
      System.out.println("Idade: " + p.getIdade());
      System.out.println("Salário: " + p.getSalario() + "\n");
    }
  }
}
