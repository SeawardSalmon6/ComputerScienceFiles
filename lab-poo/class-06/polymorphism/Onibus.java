public class Onibus extends Veiculo {
  private int quantAssentos;

  public Onibus() {
    this(0, 0, "", "", 0);
  }

  public Onibus(int ano, int quantPneus, String modelo, String placa, int quantAssentos) {
    super(ano, quantPneus, modelo, placa);
    this.setQuantAssentos(quantAssentos);
  }

  public int getQuantAssentos() {
    return quantAssentos;
  }

  public void setQuantAssentos(int quantAssentos) {
    this.quantAssentos = quantAssentos;
  }
}
