public class Onibus {
	private String modelo;
	private String marca;
	private int anoFabricacao;
	private int[][] assentos = new int[12][4];
	private double quilometragem;

	public Onibus() {
		this("", "", 0, null, 0);
	}

	public Onibus(String modelo, String marca, int anoFabricacao, int[][] assentos, double quilometragem) {
		this.setModelo(modelo);
		this.setMarca(marca);
		this.setAnoFabricacao(anoFabricacao);
		this.setAssentos(assentos);
		this.setQuilometragem(quilometragem);
	}

	public String getModelo() {
		return modelo;
	}

	public double getQuilometragem() {
		return quilometragem;
	}

	public int[][] getAssentos() {
		return assentos;
	}

	public int getAnoFabricacao() {
		return anoFabricacao;
	}

	public String getMarca() {
		return marca;
	}

	public void setQuilometragem(double quilometragem) {
		this.quilometragem = quilometragem;
	}

	public void setAssentos(int[][] assentos) {
		this.assentos = assentos;
	}

	public void setAnoFabricacao(int anoFabricacao) {
		this.anoFabricacao = anoFabricacao;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}
}