public class Motorista {
	private static int qtdMotoristas = 0;

	private int idMotorista;
	private String cnh;
	private String nome;
	private Data dataAdmissao;

	// =============== Métodos da Classe
	public String gerarDataAdmissao() {
		return this.dataAdmissao.criarData();
	}

	// =============== Construtores
	public Motorista() {
		this(++qtdMotoristas, "", "", null);
	}

	public Motorista(int idMotorista, String cnh, String nome, Data dataAdmissao) {
		this.setIdMotorista(idMotorista);
		this.setCnh(cnh);
		this.setNome(nome);
		this.setDataAdmissao(dataAdmissao);
	}

	// =============== Getters e Setters
	public int getIdMotorista() {
		return this.idMotorista;
	}

	public String getCnh() {
		return this.cnh;
	}

	public String getNome() {
		return this.nome;
	}

	public Data getDataAdmissao() {
		return this.dataAdmissao;
	}

	public void setIdMotorista(int idMotorista) {
		this.idMotorista = idMotorista;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public void setCnh(String cnh) {
		this.cnh = cnh;
	}

	public void setDataAdmissao(Data dataAdmissao) {
		this.dataAdmissao = dataAdmissao;
	}
}