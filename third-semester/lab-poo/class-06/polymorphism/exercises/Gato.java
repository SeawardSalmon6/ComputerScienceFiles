public class Gato extends Animal {
  public Gato() {
    this("", "", 0);
  }

  public Gato(String nomeCientifico, String nomePopular, int qtdMembros) {
    super(nomeCientifico, nomePopular, qtdMembros);
  }

  public void comunicar() {
    System.out.println("Gato: miau, miau!");
  }

  public void movimentar() {
    System.out.println("Gato: estou caminhando...");
  }
}
