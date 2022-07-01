public class Caminhao implements Motor, Carroceria {
  private String marca;
  private String modelo;
  private String tipoMotor;
  private String tipoCombustivel;
  private String tipoCarroceria;

  public Caminhao() {
    this("", "", "", "", "");
  }

  public Caminhao(String marca, String modelo, String tipoMotor, String tipoCombustivel, String tipoCarroceria) {
    this.setMarca(marca);
    this.setModelo(modelo);
    this.setTipoMotor(tipoMotor);
    this.setTipoCombustivel(tipoCombustivel);
    this.setTipoCarroceria(tipoCarroceria);
  }

  public String getMarca() {
    return this.marca;
  }

  public String getModelo() {
    return this.modelo;
  }

  public String getTipoMotor() {
    return this.tipoMotor;
  }

  public String getTipoCombustivel() {
    return this.tipoCombustivel;
  }

  public String getTipoCarroceria() {
    return this.tipoCarroceria;
  }

  public void setMarca(String marca) {
    this.marca = marca;
  }

  public void setModelo(String modelo) {
    this.modelo = modelo;
  }

  public void setTipoMotor(String tipoMotor) {
    this.tipoMotor = tipoMotor;
  }

  public void setTipoCombustivel(String tipoCombustivel) {
    this.tipoCombustivel = tipoCombustivel;
  }

  public void setTipoCarroceria(String tipoCarroceria) {
    this.tipoCarroceria = tipoCarroceria;
  }
}
