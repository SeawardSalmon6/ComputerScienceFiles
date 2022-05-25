public class Passageiro {
	private String rg;
	private String nome;
	private Data dataNascimento;
	private String endereco;

	public Passageiro() {
		this("", "", null, "");
	}

	public Passageiro(String rg) {
		this.setRg(rg);
	}

	public Passageiro(String rg, String nome) {
		this.setRg(rg);
		this.setNome(nome);
	}

	public Passageiro(String rg, String nome, Data dataNascimento) {
		this.setRg(rg);
		this.setNome(nome);
		this.setDataNascimento(dataNascimento);
	}

	public Passageiro(String rg, String nome, Data dataNascimento, String endereco) {
		this.setRg(rg);
		this.setNome(nome);
		this.setDataNascimento(dataNascimento);
		this.setEndereco(endereco);
	}

	public String getRg() {
		return rg;
	}

	public String getEndereco() {
		return endereco;
	}

	public Data getDataNascimento() {
		return dataNascimento;
	}

	public String getNome() {
		return nome;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public void setDataNascimento(Data dataNascimento) {
		this.dataNascimento = dataNascimento;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setRg(String rg) {
		this.rg = rg;
	}
}