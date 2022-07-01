public class Arara extends Animal {
  public Arara() {
    this("", "", 0);
  }

  public Arara(String nomeCientifico, String nomePopular, int qtdMembros) {
    super(nomeCientifico, nomePopular, qtdMembros);
  }

  public void comunicar() {
    System.out.println("Arara: reco-reco, reco-reco!");
  }

  public void movimentar() {
    System.out.println("Arara: estou voando por aí...");
  }
}
