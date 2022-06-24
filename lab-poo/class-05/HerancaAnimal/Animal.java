public class Animal {
  private String nomePopular;
  private String nomeCientifico;
  private String classe;
  private String especie;
  private int qtdMembros;

  // =========== Construtores
  public Animal() {
    this("", "", "", "", 0);
  }

  public Animal(String nomePopular, String nomeCientifico, String classe, String especie, int qtdMembros) {
    this.setNomePopular(nomePopular);
    this.setNomeCientifico(nomeCientifico);
    this.setClasse(classe);
    this.setEspecie(especie);
    this.setQtdMembros(qtdMembros);
  }

  // =========== Getters e Setters
  public String getNomePopular() {
    return this.nomePopular;
  }

  public String getNomeCientifico() {
    return this.nomeCientifico;
  }

  public String getClasse() {
    return this.classe;
  }

  public String getEspecie() {
    return this.especie;
  }

  public int getQtdMembros() {
    return this.qtdMembros;
  }

  public void setNomePopular(String nomePopular) {
    this.nomePopular = nomePopular;
  }

  public void setNomeCientifico(String nomeCientifico) {
    this.nomeCientifico = nomeCientifico;
  }

  public void setClasse(String classe) {
    this.classe = classe;
  }

  public void setEspecie(String especie) {
    this.especie = especie;
  }

  public void setQtdMembros(int qtdMembros) {
    this.qtdMembros = qtdMembros;
  }
}
