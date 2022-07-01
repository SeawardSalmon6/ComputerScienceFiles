public abstract class Animal {
  private String nomeCientifico;
  private String nomePopular;
  private int qtdMembros;

  public abstract void comunicar();

  public abstract void movimentar();

  public Animal() {
    this("", "", 0);
  }

  public Animal(String nomeCientifico, String nomePopular, int qtdMembros) {
    this.setNomeCientifico(nomeCientifico);
    this.setNomePopular(nomePopular);
    this.setQtdMembros(qtdMembros);
  }

  public String getNomeCientifico() {
    return this.nomeCientifico;
  }

  public String getNomePopular() {
    return this.nomePopular;
  }

  public int getQtdMembros() {
    return this.qtdMembros;
  }

  public void setNomeCientifico(String nomeCientifico) {
    this.nomeCientifico = nomeCientifico;
  }

  public void setNomePopular(String nomePopular) {
    this.nomePopular = nomePopular;
  }

  public void setQtdMembros(int qtdMembros) {
    this.qtdMembros = qtdMembros;
  }
}