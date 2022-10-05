import java.util.ArrayList;
import java.util.Scanner;

public class Turma {
	static final int MAX_ALUNOS = 40;

	private String nomeTurma;
	private static int qtdAlunos = 0;
	private ArrayList<Aluno> alunos = new ArrayList<>();

	public Turma() {
		this("", null);
	}

	public Turma(String nomeTurma) {
		this.setNomeTurma(nomeTurma);
	}

	public Turma(String nomeTurma, ArrayList<Aluno> alunos) {
		this.setNomeTurma(nomeTurma);
		this.setAlunos(alunos);
	}

	public String getNomeTurma() {
		return nomeTurma;
	}

	public static int getQtdAlunos() {
		return qtdAlunos;
	}

	public ArrayList<Aluno> getAlunos() {
		return alunos;
	}

	public static void setQtdAlunos(int qtdAlunos) {
		if (qtdAlunos >= 0) {
			Turma.qtdAlunos = qtdAlunos;
		} else {
			System.out.println("Valor atribuído é inválido!");
		}
	}

	public void setAlunos(ArrayList<Aluno> alunos) {
		this.alunos = alunos;
	}

	public void setNomeTurma(String nomeTurma) {
		this.nomeTurma = nomeTurma;
	}

	public void novoAluno(Scanner sc) {
		Aluno novoAluno = new Aluno();
		char resp = 'n';

		System.out.print("\n- Insira o nome do aluno: ");
		novoAluno.setNomeCompleto(sc.nextLine());

		System.out.print("\n- Insira o RA do aluno: ");
		novoAluno.setRa(sc.nextLine());

		System.out.print("\n- Insira a idade do aluno: ");
		novoAluno.setIdade(sc.nextInt());
		sc.nextLine();

		System.out.print("\n---> Deseja inserir os dados complementares (s/n)?  ");
		resp = sc.next().charAt(0);
		sc.nextLine();

		if (Character.toLowerCase(resp) == 's') {
			System.out.print("\n- Insira o CPF do aluno: ");
			novoAluno.setCpf(sc.nextLine());

			System.out.print("\n- Insira o telefone do aluno: ");
			novoAluno.setTelefone(sc.nextLine());
		}

		this.adicionarAluno(novoAluno);
	}

	public void adicionarAluno(Aluno novoAluno) {
		this.alunos.add(novoAluno);
	}

	public void removerAluno(Scanner sc) {
		String nomeAluno;

		System.out.print("\n\n---> Insira o nome do aluno: ");
		nomeAluno = sc.nextLine();

		this.removerAluno(nomeAluno);
	}

	public void removerAluno(String nomeAluno) {
		int posicao = this.buscarAluno(nomeAluno);
		if (posicao >= 0) {
			this.alunos.remove(posicao);
		} else {
			System.out.println("\n--> Aluno não encontrado!");
		}
	}

	private int buscarAluno(String nomeAluno) {
		for (int i = 0; i < alunos.size(); i++) {
			if (nomeAluno.equalsIgnoreCase(alunos.get(i).getNomeCompleto()))
				return i;
		}
		return -1;
	}

	public void exibeAluno(Scanner sc) {
		String nomeAluno;

		System.out.print("\n\n---> Insira o nome do aluno: ");
		nomeAluno = sc.nextLine();

		this.exibeAluno(nomeAluno);
	}

	public void exibeAluno(String nomeAluno) {
		int posicao = this.buscarAluno(nomeAluno);
		Aluno aluno = this.alunos.get(posicao);

		if (posicao >= 0) {
			System.out.println("\n\n========= Aluno " + aluno.getNomeCompleto());
			System.out.println("- RA: " + aluno.getRa());
			System.out.println("- Idade: " + aluno.getIdade());
			System.out.println("- CPF: " + aluno.getCpf());
			System.out.println("- Telefone: " + aluno.getTelefone());
		} else {
			System.out.println("\n--> Aluno não encontrado!");
		}
	}
}