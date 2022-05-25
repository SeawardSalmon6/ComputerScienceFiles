public class Data {
	private int dia;
	private int mes;
	private int ano;

	public Data() {
		this(0, 0, 0);
	}

	public Data(int dia, int mes, int ano) {
		this.setDia(dia);
		this.setMes(mes);
		this.setAno(ano);
	}

	public int getDia() {
		return dia;
	}

	public int getAno() {
		return ano;
	}

	public int getMes() {
		return mes;
	}

	public void setAno(int ano) {
		this.ano = ano;
	}

	public void setMes(int mes) {
		this.mes = mes;
	}

	public void setDia(int dia) {
		this.dia = dia;
	}
}