public class Televisao implements Aparelho {
  private double preco;
  private double imposto;
  private String nome;
  private String descricao;

  public Televisao() {
    this(0.0, 0.0, "", "");
  }

  public Televisao(double preco, double imposto, String nome, String descricao) {
    this.setPreco(preco);
    this.setImposto(imposto);
    this.setNome(nome);
    this.setDescricao(descricao);
  }

  public double getPreco() {
    return preco;
  }

  public double getImposto() {
    return imposto;
  }

  public String getNome() {
    return nome;
  }

  public String getDescricao() {
    return descricao;
  }

  public void setPreco(double preco) {
    this.preco = preco;
  }

  public void setImposto(double imposto) {
    this.imposto = imposto;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setDescricao(String descricao) {
    this.descricao = descricao;
  }
}
