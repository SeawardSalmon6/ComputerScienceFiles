public class Celular implements Aparelho, Movel {
  private double preco;
  private String nome;
  private String descricao;
  private double credito;

  public double calculaCredito() {
    return this.credito;
  }

  public Celular() {
    this(0.0, "", "", 0.0);
  }

  public Celular(double preco, String nome, String descricao, double credito) {
    this.setPreco(preco);
    this.setNome(nome);
    this.setDescricao(descricao);
    this.setCredito(credito);
  }

  public double getPreco() {
    return this.preco;
  }

  public String getNome() {
    return this.nome;
  }

  public String getDescricao() {
    return this.descricao;
  }

  public void setPreco(double preco) {
    this.preco = preco;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setDescricao(String descricao) {
    this.descricao = descricao;
  }

  public void setCredito(double credito) {
    this.credito = credito;
  }
}
