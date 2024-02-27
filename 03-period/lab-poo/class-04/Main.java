import java.util.Scanner;

public class Main {
	public static int mostrarMenu(Scanner sc) {
		int op;

		do {
			System.out.println("\n\n========= Gerenciar Alunos");
			System.out.println(" [1] - Adicionar Aluno");
			System.out.println(" [2] - Exibir Aluno");
			System.out.println(" [3] - Remover Aluno");
			System.out.println(" [4] - Cancelar");

			System.out.print("\n---> Escolha uma opção: ");
			op = sc.nextInt();
			sc.nextLine();

			if (op < 1 || op > 4) {
				System.out.println("\n--> Aviso: insira uma opção válida!\n");
			}
		} while (op < 1 || op > 4);

		return op;
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Turma comp = new Turma("COMPUTARIA");
		int op;

		do {
			op = mostrarMenu(sc);

			switch (op) {
				case 1:
					comp.novoAluno(sc);
					break;
				case 2:
					comp.exibeAluno(sc);
					break;
				case 3:
					comp.removerAluno(sc);
					break;
				case 4:
					System.out.println("\nObrigado por utilizar nossa aplicação.");
				default:
					break;
			}
		} while (op != 4);

		sc.close();
	}
}
