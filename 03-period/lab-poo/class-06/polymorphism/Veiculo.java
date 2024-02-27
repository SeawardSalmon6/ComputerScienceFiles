public class Veiculo {
  private int ano;
  private int quantPneus;
  private String modelo;
  private String placa;

  public Veiculo() {
    this(0, 0, "", "");
  }

  public Veiculo(int ano, int quantPneus, String modelo, String placa) {
    this.setAno(ano);
    this.setQuantPneus(quantPneus);
    this.setModelo(modelo);
    this.setPlaca(placa);
  }

  public int getAno() {
    return this.ano;
  }

  public int getQuantPneus() {
    return this.quantPneus;
  }

  public String getModelo() {
    return this.modelo;
  }

  public String getPlaca() {
    return this.placa;
  }

  public void setAno(int ano) {
    this.ano = ano;
  }

  public void setQuantPneus(int quantPneus) {
    this.quantPneus = quantPneus;
  }

  public void setModelo(String modelo) {
    this.modelo = modelo;
  }

  public void setPlaca(String placa) {
    this.placa = placa;
  }

}