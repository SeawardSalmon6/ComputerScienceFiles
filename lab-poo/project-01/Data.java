public class Data {
	private int dia;
	private int mes;
	private int ano;

	// =============== Métodos da Classe
	public String criarData() {
		return String.format("%02d", this.dia) + "/" + String.format("%02d", this.mes) + "/" + this.ano;
	}

	// =============== Construtores
	public Data() {
		this(1, 1, 2022);
	}

	public Data(int dia, int mes, int ano) {
		this.setDia(dia);
		this.setMes(mes);
		this.setAno(ano);
	}

	// =============== Getters e Setters

	public int getDia() {
		return this.dia;
	}

	public int getMes() {
		return this.mes;
	}

	public int getAno() {
		return this.ano;
	}

	public void setData(Data data) {
		this.setDia(data.getDia());
		this.setMes(data.getMes());
		this.setAno(data.getAno());
	}

	public void setDia(int dia) {
		if (this.mes % 2 != 0) {
			if (dia >= 1 && dia <= 31) {
				this.dia = dia;
			} else {
				System.out.println("\n==!== AVISO: Insira um dia válido!");
			}
		} else {
			if (this.mes == 2) {
				if (dia >= 1 && dia <= 28) {
					this.dia = dia;
				} else {
					System.out.println("\n==!== AVISO: Insira um dia válido!");
				}
			} else {
				if (dia >= 1 && dia <= 30) {
					this.dia = dia;
				} else {
					System.out.println("\n==!== AVISO: Insira um dia válido!");
				}
			}
		}
	}

	public void setMes(int mes) {
		if (mes >= 1 && mes <= 12) {
			this.mes = mes;
		} else {
			System.out.println("\n==!== AVISO: Insira um mês válido!");
		}
	}

	public void setAno(int ano) {
		if (ano >= 1900 && ano < 2023) {
			this.ano = ano;
		} else {
			System.out.println("\n==!== AVISO: Insira um mês válido!");
		}
	}
}