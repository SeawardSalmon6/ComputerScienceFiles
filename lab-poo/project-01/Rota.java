public class Rota {
	private String origem;
	private String parada;
	private String destino;
	private Hora chegada;
	private Hora saida;

	public Rota() {
		this("", "", "", null, null);
	}

	public Rota(String origem, String parada, String destino, Hora chegada, Hora saida) {
		this.setOrigem(origem);
		this.setParada(parada);
		this.setDestino(destino);
		this.setChegada(chegada);
		this.setSaida(saida);
	}

	public String getOrigem() {
		return origem;
	}

	public Hora getSaida() {
		return saida;
	}

	public Hora getChegada() {
		return chegada;
	}

	public String getDestino() {
		return destino;
	}

	public String getParada() {
		return parada;
	}

	public void setSaida(Hora saida) {
		this.saida = saida;
	}

	public void setChegada(Hora chegada) {
		this.chegada = chegada;
	}

	public void setDestino(String destino) {
		this.destino = destino;
	}

	public void setParada(String parada) {
		this.parada = parada;
	}

	public void setOrigem(String origem) {
		this.origem = origem;
	}
}