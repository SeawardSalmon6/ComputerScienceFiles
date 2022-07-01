public class Hora {
	private int horas;
	private int minutos;

	// ================= Métodos da Classe
	public String criarHorario() {
		return String.format("%02d", this.horas) + ":" + String.format("%02d", this.minutos);
	}

	// ================= Construtores
	public Hora() {
		this(0, 0);
	}

	public Hora(int horas, int minutos) {
		this.setHoras(horas);
		this.setMinutos(minutos);
	}

	// ================= Getters e Setters
	public int getHoras() {
		return this.horas;
	}

	public int getMinutos() {
		return this.minutos;
	}

	public void setHoras(int horas) {
		if (horas >= 0 && horas <= 23) {
			this.horas = horas;
		} else {
			System.out.println("\n==!== AVISO: Insira horas válidas!");
		}
	}

	public void setMinutos(int minutos) {
		if (minutos >= 0 && minutos <= 59) {
			this.minutos = minutos;
		} else {
			System.out.println("\n==!== AVISO: Insira minutos válidos!");
		}
	}
}