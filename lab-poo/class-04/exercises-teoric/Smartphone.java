public class Smartphone {
  private String nome;
  private String marca;
  private double preco;
  private boolean acompanhaCarregador;

  public Smartphone() {
    this("", "", 0, true);
  }

  public Smartphone(String nome, String marca) {
    this.setNome(nome);
    this.setMarca(marca);
  }

  public Smartphone(String nome, String marca, double preco, boolean acompanhaCarregador) {
    this.setNome(nome);
    this.setMarca(marca);
    this.setPreco(preco);
    this.setAcompanhaCarregador(acompanhaCarregador);
  }

  public String getNome() {
    return nome;
  }

  public double getPreco() {
    return preco;
  }

  public String getMarca() {
    return marca;
  }

  public boolean getAcompanhaCarregador() {
    return acompanhaCarregador;
  }

  public void setAcompanhaCarregador(boolean acompanhaCarregador) {
    this.acompanhaCarregador = acompanhaCarregador;
  }

  public void setPreco(double preco) {
    this.preco = preco;
  }

  public void setMarca(String marca) {
    this.marca = marca;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

}
