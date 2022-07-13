public class Pessoa {
  private String nome;
  private int idade;

  public Pessoa() {
    this("", 0);
  }

  public Pessoa(String nome, int idade) {
    this.setNome(nome);
    this.setIdade(idade);
  }

  public String getNome() {
    return this.nome;
  }

  public int getIdade() {
    return this.idade;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }

}
