public abstract class Peca {
  private String nome;

  public abstract void mover();

  public Peca() {
    this("");
  }

  public Peca(String nome) {
    this.setNome(nome);
  }

  public String getNome() {
    return this.nome;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }
}