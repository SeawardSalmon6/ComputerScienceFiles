public class Carro extends Veiculo {
  private String proprietario;
  private int ultimaRevisao;

  public Carro(String proprietario, int ultimaRevisao) {
    this.setProprietario(proprietario);
    this.setUltimaRevisao(ultimaRevisao);
  }

  public Carro(int ano, int quantPneus, String modelo, String placa, String proprietario, int ultimaRevisao) {
    super(ano, quantPneus, modelo, placa);
    this.setProprietario(proprietario);
    this.setUltimaRevisao(ultimaRevisao);
  }

  public String getProprietario() {
    return this.proprietario;
  }

  public int getUltimaRevisao() {
    return this.ultimaRevisao;
  }

  public void setProprietario(String proprietario) {
    this.proprietario = proprietario;
  }

  public void setUltimaRevisao(int ultimaRevisao) {
    this.ultimaRevisao = ultimaRevisao;
  }
}
