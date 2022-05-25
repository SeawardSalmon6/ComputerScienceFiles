public class Motorista {
	private String cnh;
	private String nome;
	private Data dataAdmissao;

	public Motorista() {
		this("", "", null);
	}

	public Motorista(String cnh, String nome, Data dataAdmissao) {
		this.setCnh(cnh);
		this.setNome(nome);
		this.setDataAdmissao(dataAdmissao);
	}

	public Data getDataAdmissao() {
		return dataAdmissao;
	}

	public String getCnh() {
		return cnh;
	}

	public String getNome() {
		return nome;
	}

	public void setCnh(String cnh) {
		this.cnh = cnh;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setDataAdmissao(Data dataAdmissao) {
		this.dataAdmissao = dataAdmissao;
	}
}