import java.util.ArrayList;
import java.util.Scanner;

public class ListaMotoristas {
	private static ArrayList<Motorista> listaMotoristas = new ArrayList<>();

	// =================== Métodos Auxiliares
	public static int getQuantidade() {
		return listaMotoristas.size();
	}

	public static void exibirMotorista(Motorista motorista, int index) {
		System.out.println("\n---> Motorista " + String.format("%02d", index));
		System.out.println("\t- Nome: " + motorista.getNome());
		System.out.println("\t- CNH: " + motorista.getCnh());
		System.out.println("\t- Data de Admissão: " + motorista.gerarDataAdmissao());
		System.out.println("---------------------------------------");
	}

	public static void exibirMotorista(Motorista motorista) {
		System.out.println("\n| *** Opção [" + motorista.getIdMotorista() + "]");
		System.out.println("|\t- Nome: " + motorista.getNome());
		System.out.println("|\t- CNH: " + motorista.getCnh());
		System.out.println("|\t- Data de Admissão: " + motorista.gerarDataAdmissao());
		System.out.println("---------------------------------------");
	}

	public static void listarOpcoesMotoristas() {
		System.out.println("\n=========> Lista de Motoristas");

		if (listaMotoristas.size() == 0) {
			System.out.println("\n--> Não existem motoristas cadastrados.");
			Utils.aguardarTecla();
			return;
		}

		for (int i = 0; i < listaMotoristas.size(); i++)
			exibirMotorista(listaMotoristas.get(i));
	}

	public static Motorista buscarMotorista(int id) {
		if (listaMotoristas.size() == 0) {
			System.out.println("\n--> Não existem motoristas cadastrados.");
			Utils.aguardarTecla();
			return null;
		}

		for (int i = 0; i < listaMotoristas.size(); i++) {
			if (listaMotoristas.get(i).getIdMotorista() == id)
				return listaMotoristas.get(i);
		}

		return null;
	}

	// =================== Métodos da Classe
	public static void cadastrarMotorista(Scanner input) {
		Motorista novoMotorista = new Motorista();
		Data novaData = new Data();

		System.out.println("\n========= CADASTRAR MOTORISTA");
		System.out.print("\n--> Digite o nome do motorista: ");
		novoMotorista.setNome(input.nextLine());

		System.out.print("\n--> Digite o número da CNH: ");
		novoMotorista.setCnh(input.nextLine());

		System.out.println("\n---- Insira a Data de Admissão");
		System.out.print("\t--> Dia: ");
		novaData.setDia(input.nextInt());
		input.nextLine();

		System.out.print("\t--> Mês: ");
		novaData.setMes(input.nextInt());
		input.nextLine();

		System.out.print("\t--> Ano: ");
		novaData.setAno(input.nextInt());
		input.nextLine();

		novoMotorista.setDataAdmissao(novaData);
		listaMotoristas.add(novoMotorista);

		System.out.println("\n\n==> Motorista cadastrado com sucesso!");
		Utils.aguardarTecla();
	}

	public static void listarMotoristas() {
		System.out.println("\n========= LISTA DE MOTORISTAS");

		if (listaMotoristas.size() == 0) {
			System.out.println("\n--> Não existem motoristas cadastrados.");
			Utils.aguardarTecla();
			return;
		}

		for (int i = 0; i < listaMotoristas.size(); i++)
			exibirMotorista(listaMotoristas.get(i), i + 1);

		Utils.aguardarTecla();
	}

	public static void alterarMotorista(Scanner input) {
		Motorista motorista;
		int id;
		int opMenu;

		if (ListaMotoristas.getQuantidade() == 0) {
			System.out.println("\n--> Não existem motoristas cadastrados.");
			Utils.aguardarTecla();
			return;
		}

		Utils.limpaTela();

		System.out.println("\n========= ALTERAR DADOS DO MOTORISTA");
		ListaMotoristas.listarMotoristas();

		System.out.print("\n--> Digite o ID do motorista que deseja alterar: ");
		id = input.nextInt();
		input.nextLine();

		motorista = ListaMotoristas.buscarMotorista(id);

		if (motorista == null) {
			System.out.println("\n==!== AVISO: o ID informado não foi encontrado!");
			Utils.aguardarTecla();
			return;
		}

		do {
			Utils.limpaTela();

			System.out.println("\n========= ALTERAR DADOS DO MOTORISTA");
			ListaMotoristas.exibirMotorista(motorista);

			System.out.println("\n--> Qual dado deseja alterar?");
			System.out.println("(1) Alterar Nome");
			System.out.println("(2) Alterar Número da CNH");
			System.out.println("(3) Alterar Data de Admissão");
			System.out.println("(9) Cancelar Alterações e Voltar");

			System.out.println("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					System.out.print("\n--> Digite o novo nome: ");
					motorista.setNome(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 2:
					System.out.print("\n--> Digite o novo número da CNH: ");
					motorista.setCnh(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 3:
					Data novaData = motorista.getDataAdmissao();
					System.out.println("\n---- Insira a nova data de admissão");
					System.out.print("\t--> Dia: ");
					novaData.setDia(input.nextInt());
					input.nextLine();

					System.out.print("\t--> Mês: ");
					novaData.setMes(input.nextInt());
					input.nextLine();

					System.out.print("\t--> Ano: ");
					novaData.setAno(input.nextInt());
					input.nextLine();

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 9:
					break;
				default:
					System.out.println("\n==!== AVISO: Insira uma opção válida!");
					Utils.aguardarTecla();
					break;
			}
		} while (opMenu != 9);

		Utils.aguardarTecla();
	}

	public static void excluirMotorista(Scanner input) {
		Motorista motorista;
		int idM;

		if (ListaMotoristas.getQuantidade() == 0) {
			System.out.println("\n========= EXCLUIR MOTORISTA");
			System.out.println("\n--> Não existem motoristas cadastrados.");
			Utils.aguardarTecla();
			return;
		}

		System.out.println("\n========= EXCLUIR MOTORISTA");
		System.out.print("\n--> Digite o ID do motorista que deseja excluir: ");
		idM = input.nextInt();
		input.nextLine();

		motorista = ListaMotoristas.buscarMotorista(idM);

		if (motorista == null) {
			System.out.println("\n==!== AVISO: o ID informado não foi encontrado!");
			Utils.aguardarTecla();
			return;
		}

		listaMotoristas.remove(motorista);
		System.out.println("\n\n==> Motorista removido com sucesso!");

		Utils.aguardarTecla();
	}
}
