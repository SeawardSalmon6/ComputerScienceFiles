public class Passageiro {
	private String rg;
	private String nome;
	private Data dataNascimento;
	private String endereco;

	// =============== Relacionamentos com Outras Classes
	Passagem minhaPassagem;

	// =============== Métodos da Classe
	public String gerarDataNascimento() {
		return this.dataNascimento.criarData();
	}

	public void atribuirPassagem(Passagem novaPassagem) {
		this.minhaPassagem = novaPassagem;
	}

	// =============== Construtores
	public Passageiro() {
		this("", "", null, "");
	}

	public Passageiro(String rg, String nome, Data dataNascimento, String endereco) {
		this.setRg(rg);
		this.setNome(nome);
		this.setDataNascimento(dataNascimento);
		this.setEndereco(endereco);
	}

	// =============== Getters e Setters
	public String getRg() {
		return this.rg;
	}

	public String getNome() {
		return this.nome;
	}

	public Data getDataNascimento() {
		return this.dataNascimento;
	}

	public String getEndereco() {
		return this.endereco;
	}

	public Passagem getMinhaPassagem() {
		return this.minhaPassagem;
	}

	public void setRg(String rg) {
		this.rg = rg;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setDataNascimento(Data dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public void setMinhaPassagem(Passagem minhaPassagem) {
		this.minhaPassagem = minhaPassagem;
	}
}