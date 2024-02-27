public class Cachorro extends Animal {
  public Cachorro() {
    this("", "", 0);
  }

  public Cachorro(String nomeCientifico, String nomePopular, int qtdMembros) {
    super(nomeCientifico, nomePopular, qtdMembros);
  }

  public void comunicar() {
    System.out.println("Cachorro: Whoof, whoof!");
  }

  public void movimentar() {
    System.out.println("Cachorro: estou caminhando...");
  }
}
