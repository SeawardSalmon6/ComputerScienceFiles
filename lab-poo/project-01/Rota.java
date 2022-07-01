public class Rota {
	private static int qtdRotas = 0;

	private int idRota;
	private boolean rotaDisponivel;
	private String origem;
	private String parada;
	private String destino;
	private Hora chegada;
	private Hora saida;
	private double valor;

	// =============== Relacionamentos com Outras Classes
	private Onibus onibusDaRota;
	private Motorista motoristaDaRota;

	// =============== Métodos da Classe
	public void atribuirOnibus(Onibus onibus) {
		this.setOnibusDaRota(onibus);
		this.atualizarRotaDisponivel();
	}

	public void atribuirMotorista(Motorista motorista) {
		this.setMotoristaDaRota(motorista);
		this.atualizarRotaDisponivel();
	}

	private void atualizarRotaDisponivel() {
		if (onibusDaRota != null && motoristaDaRota != null) {
			this.setRotaDisponivel(true);
		} else {
			this.setRotaDisponivel(false);
		}
	}

	public String gerarSaida() {
		return this.saida.criarHorario();
	}

	public String gerarChegada() {
		return this.chegada.criarHorario();
	}

	// =============== Construtores
	public Rota() {
		this(++qtdRotas, false, "", "", "", null, null, null, null, 0.0);
	}

	public Rota(int idRota, boolean rotaDisponivel, String origem, String parada, String destino, Hora chegada,
			Hora saida, Onibus onibus, Motorista motorista, double valor) {
		this.setIdRota(idRota);
		this.setRotaDisponivel(rotaDisponivel);
		this.setOrigem(origem);
		this.setParada(parada);
		this.setDestino(destino);
		this.setChegada(chegada);
		this.setSaida(saida);
		this.setOnibusDaRota(onibus);
		this.setMotoristaDaRota(motorista);
		this.setValor(valor);
	}

	// ================= Getters e Setters
	public int getIdRota() {
		return this.idRota;
	}

	public boolean getRotaDisponivel() {
		return this.rotaDisponivel;
	}

	public String getOrigem() {
		return this.origem;
	}

	public String getParada() {
		return this.parada;
	}

	public String getDestino() {
		return this.destino;
	}

	public Hora getChegada() {
		return this.chegada;
	}

	public Hora getSaida() {
		return this.saida;
	}

	public double getValor() {
		return this.valor;
	}

	public Onibus getOnibusDaRota() {
		return this.onibusDaRota;
	}

	public Motorista getMotoristaDaRota() {
		return this.motoristaDaRota;
	}

	public void setIdRota(int id) {
		this.idRota = id;
	}

	public void setRotaDisponivel(boolean rotaDisponivel) {
		this.rotaDisponivel = rotaDisponivel;
	}

	public void setOrigem(String origem) {
		this.origem = origem;
	}

	public void setParada(String parada) {
		this.parada = parada;
	}

	public void setDestino(String destino) {
		this.destino = destino;
	}

	public void setSaida(Hora saida) {
		this.saida = saida;
	}

	public void setChegada(Hora chegada) {
		this.chegada = chegada;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}

	public void setMotoristaDaRota(Motorista motorista) {
		this.motoristaDaRota = motorista;
	}

	public void setOnibusDaRota(Onibus onibus) {
		this.onibusDaRota = onibus;
	}
}