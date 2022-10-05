public class Cachorro extends Animal {
  private String raca;
  private boolean dono;

  // =========== Métodos da Classe
  public void ganharCachorro() {
    this.dono = true;
  }

  public void venderCachorro() {
    this.dono = false;
  }

  // =========== Construtores
  public Cachorro() {
    this("", "", "", "", 0, "", false);
  }

  public Cachorro(String nomePopular, String nomeCientifico, String classe, String especie, int qtdMembros, String raca,
      boolean dono) {
    super(nomePopular, nomeCientifico, classe, especie, qtdMembros);
    this.setRaca(raca);

    if (dono)
      this.ganharCachorro();
    else
      this.venderCachorro();
  }

  // =========== Getters e Setters
  public String getRaca() {
    return this.raca;
  }

  public boolean temDono() {
    return this.dono;
  }

  public void setRaca(String raca) {
    this.raca = raca;
  }
}
