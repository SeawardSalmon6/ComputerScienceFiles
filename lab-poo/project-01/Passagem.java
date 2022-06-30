public class Passagem {
	private Passageiro passageiro;
	private Rota rotaPassagem;
	private int assentoLinha;
	private int assentoColuna;

	// ================ Métodos da Classe
	public void exibirPassagem() {
		System.out.println("\n------> Passagem");
		System.out.println("\t- Passageiro " + this.passageiro.getNome());
		System.out.println("\t- Cidade Origem: " + this.rotaPassagem.getOrigem());
		System.out.println("\t====> Horário de Saída: " + this.rotaPassagem.gerarSaida());
		System.out.println("\n\t- Cidade Escala (Parada): " + this.rotaPassagem.getParada());
		System.out.println("\n\t- Cidade Destino: " + this.rotaPassagem.getDestino());
		System.out.println("\t====> Horário de Chegada: " + this.rotaPassagem.gerarChegada());
		System.out.println("\n\t- Motorista: " + this.rotaPassagem.getMotoristaDaRota().getNome());
		System.out.println("---------------------------------------");
	}

	public void atribuirAssento(int assentoLinha, int assentoColuna) {
		this.assentoLinha = assentoLinha;
		this.assentoColuna = assentoColuna;
	}

	// ================ Construtores
	public Passagem() {
		this(null, null, -1, -1);
	}

	public Passagem(Passageiro passageiro, Rota rota, int assentoLinha, int assentoColuna) {
		this.setPassageiro(passageiro);
		this.setRotaPassagem(rota);
		this.setAssentoLinha(assentoLinha);
		this.setAssentoColuna(assentoColuna);
	}

	// ================ Getters e Setters
	public Passageiro getPassageiro() {
		return this.passageiro;
	}

	public Rota getRotaPassagem() {
		return this.rotaPassagem;
	}

	public int getAssentoLinha() {
		return this.assentoLinha;
	}

	public int getAssentoColuna() {
		return this.assentoColuna;
	}

	public void setPassageiro(Passageiro passageiro) {
		this.passageiro = passageiro;
	}

	public void setRotaPassagem(Rota rota) {
		this.rotaPassagem = rota;
	}

	public void setAssentoLinha(int assentoLinha) {
		this.assentoLinha = assentoLinha;
	}

	public void setAssentoColuna(int assentoColuna) {
		this.assentoColuna = assentoColuna;
	}
}