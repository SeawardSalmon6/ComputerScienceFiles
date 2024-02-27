public class Peixe extends Animal {
  public Peixe() {
    this("", "", 0);
  }

  public Peixe(String nomeCientifico, String nomePopular, int qtdMembros) {
    super(nomeCientifico, nomePopular, qtdMembros);
  }

  public void comunicar() {
    System.out.println("Peixe: glub, glub!");
  }

  public void movimentar() {
    System.out.println("Peixe: estou nadando no meu riozinho...");
  }
}
