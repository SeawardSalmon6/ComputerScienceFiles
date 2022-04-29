package Cachorro;

public class Cachorro {
  // --> Propriedades da Classe
  private String nome;
  private String raca;
  private int idade;
  private float peso;

  // --> Propriedades da Classe
  public void latir() {
    System.out.println("Whoof whoof!");
  }

  public void comer() {
    System.out.println("Comendo ração...");
  }

  public void dormir() {
    System.out.println("Dormindo... Whoof...");
  }

  public static void main(String args[]) {
    Cachorro snoopy = new Cachorro();
    snoopy.comer();
  }
}
