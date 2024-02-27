import java.util.ArrayList;

public class CorpoDocente {
	static final int MAX_PROFESSORES = 40;

	private String departamento;
	private static int qtdDocentes;
	private ArrayList<Professor> professores = new ArrayList<>();

	public CorpoDocente() {
		this("", null);
	}

	public CorpoDocente(String departamento) {
		this.setDepartamento(departamento);
	}

	public CorpoDocente(String departamento, ArrayList<Professor> professores) {
		this.setDepartamento(departamento);
		this.setProfessores(professores);
	}

	public ArrayList<Professor> getProfessores() {
		return professores;
	}

	public String getDepartamento() {
		return departamento;
	}

	public static int getQtdDocentes() {
		return qtdDocentes;
	}

	public void setProfessores(ArrayList<Professor> professores) {
		this.professores = professores;
	}

	public static void setQtdDocentes(int qtdDocentes) {
		CorpoDocente.qtdDocentes = qtdDocentes;
	}

	public void setDepartamento(String departamento) {
		this.departamento = departamento;
	}
}
