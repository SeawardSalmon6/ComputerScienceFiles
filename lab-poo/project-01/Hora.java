public class Hora {
	private int segundos;
	private int minutos;
	private int horas;

	public Hora() {
		this(0, 0, 0);
	}

	public Hora(int segundos, int minutos, int horas) {
		this.setSegundos(segundos);
		this.setMinutos(minutos);
		this.setHoras(horas);
	}

	public int getMinutos() {
		return minutos;
	}

	public int getHoras() {
		return horas;
	}

	public int getSegundos() {
		return segundos;
	}

	public void setHoras(int horas) {
		this.horas = horas;
	}

	public void setSegundos(int segundos) {
		this.segundos = segundos;
	}

	public void setMinutos(int minutos) {
		this.minutos = minutos;
	}
}