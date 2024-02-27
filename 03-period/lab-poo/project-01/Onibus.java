import java.util.ArrayList;

public class Onibus {
	private final int QTD_LINHAS = 12;
	private final int QTD_COLUNAS = 4;

	private static int qtdOnibus = 0;

	private int idOnibus;
	private String modelo;
	private String marca;
	private int anoFabricacao;
	private double quilometragem;
	private int qtdAssentosOcupados;
	private int[][] assentos = new int[QTD_LINHAS][QTD_COLUNAS];

	// ========= Relacionamentos com Outras Classes
	private ArrayList<Passageiro> listaPassageiros = new ArrayList<>();
	private Motorista motorista;

	// =============== Métodos da Classe
	public void exibirAssentos() {
		int i, j;

		System.out.println("\n    1 2   3 4  ");
		System.out.println("    ---------  ");
		System.out.println("   /         \\ ");
		System.out.println("  /           \\");

		for (i = 0; i < QTD_LINHAS; i++) {
			System.out.print((i + 1) + " | ");

			for (j = 0; j < QTD_COLUNAS; j++)
				System.out.printf("%d ", this.assentos[i][j]);

			System.out.println("|");
		}

		System.out.println("-------------\n");
	}

	public void atribuirAssento(int assentoLinha, int assentoColuna) {
		this.assentos[assentoLinha][assentoColuna] = 1;
		this.qtdAssentosOcupados++;
	}

	public void removerAssento(int assentoLinha, int assentoColuna) {
		this.assentos[assentoLinha][assentoColuna] = 0;
		this.qtdAssentosOcupados--;
	}

	public boolean estaCheio() {
		if (this.qtdAssentosOcupados == QTD_LINHAS * QTD_COLUNAS)
			return false;

		for (int i = 0; i < QTD_LINHAS; i++) {
			for (int j = 0; j < QTD_COLUNAS; j++) {
				if (assentos[i][j] == 0) {
					return false;
				}
			}
		}

		return true;
	}

	public void atribuirMotorista(Motorista motorista) {
		this.setMotorista(motorista);
	}

	// ============== Construtores
	public Onibus() {
		this(++qtdOnibus, "", "", 0, 0, null);
	}

	public Onibus(int idOnibus, String modelo, String marca, int anoFabricacao, double quilometragem,
			Motorista motorista) {
		this.setIdOnibus(idOnibus);
		this.setModelo(modelo);
		this.setMarca(marca);
		this.setAnoFabricacao(anoFabricacao);
		this.setQuilometragem(quilometragem);
		this.setMotorista(motorista);
	}

	// =============== Getters e Setters
	public int getIdOnibus() {
		return this.idOnibus;
	}

	public String getModelo() {
		return this.modelo;
	}

	public String getMarca() {
		return this.marca;
	}

	public int getAnoFabricacao() {
		return this.anoFabricacao;
	}

	public double getQuilometragem() {
		return this.quilometragem;
	}

	public int[][] getAssentos() {
		return this.assentos;
	}

	public Motorista getMotorista() {
		return this.motorista;
	}

	public ArrayList<Passageiro> getPassageiros() {
		return this.listaPassageiros;
	}

	public void setIdOnibus(int idOnibus) {
		this.idOnibus = idOnibus;
	}

	public void setModelo(String modelo) {
		this.modelo = modelo;
	}

	public void setMarca(String marca) {
		this.marca = marca;
	}

	public void setAnoFabricacao(int anoFabricacao) {
		this.anoFabricacao = anoFabricacao;
	}

	public void setQuilometragem(double quilometragem) {
		this.quilometragem = quilometragem;
	}

	public void setAssentos(int[][] assentos) {
		this.assentos = assentos;
	}

	public void setPassageiros(ArrayList<Passageiro> passageiros) {
		this.listaPassageiros = passageiros;
	}

	public void setMotorista(Motorista motorista) {
		this.motorista = motorista;
	}
}