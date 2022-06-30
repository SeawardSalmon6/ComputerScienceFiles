import java.util.ArrayList;
import java.util.Scanner;

public class ListaOnibus {
	private static ArrayList<Onibus> listaOnibus = new ArrayList<>();

	// ================= Métodos Auxiliares
	public static int getQuantidade() {
		return listaOnibus.size();
	}

	public static void exibirOnibus(Onibus onibus, int index) {
		System.out.println("\n---> Ônibus " + String.format("%02d", index));
		System.out.println("\t- Marca: " + onibus.getMarca());
		System.out.println("\t- Modelo: " + onibus.getModelo());
		System.out.println("\t- Ano de Fabricação: " + onibus.getAnoFabricacao());
		System.out.println("\t- Quilometragem: " + onibus.getQuilometragem());
		System.out.println("---------------------------------------");
	}

	public static void exibirOnibus(Onibus onibus) {
		System.out.println("\n| *** Opção [" + onibus.getIdOnibus() + "]");
		System.out.println("|\t- Marca: " + onibus.getMarca());
		System.out.println("|\t- Modelo: " + onibus.getModelo());
		System.out.println("|\t- Ano de Fabricação: " + onibus.getAnoFabricacao());
		System.out.println("|\t- Quilometragem: " + onibus.getQuilometragem());
		System.out.println("---------------------------------------");
	}

	public static void listarOpcoesOnibus() {
		System.out.println("\n=========> Lista de Ônibus");

		if (listaOnibus.size() == 0) {
			System.out.println("\n--> Não existem ônibus cadastrados para esta rota.");
			Utils.aguardarTecla();
			return;
		}

		for (int i = 0; i < listaOnibus.size(); i++)
			exibirOnibus(listaOnibus.get(i));
	}

	public static Onibus buscarOnibus(int id) {
		if (listaOnibus.size() == 0) {
			System.out.println("\n--> Não existem ônibus cadastrados.");
			Utils.aguardarTecla();
			return null;
		}

		for (int i = 0; i < listaOnibus.size(); i++) {
			if (listaOnibus.get(i).getIdOnibus() == id) {
				return listaOnibus.get(i);
			}
		}

		return null;
	}

	// ============================ Métodos da Classe
	public static void cadastrarOnibus(Scanner input) {
		Onibus novoOnibus = new Onibus();

		System.out.println("\n========= CADASTRAR NOVO ÔNIBUS");
		System.out.print("\n--> Digite a marca: ");
		novoOnibus.setMarca(input.nextLine());

		System.out.print("\n--> Digite o modelo: ");
		novoOnibus.setModelo(input.nextLine());

		System.out.print("\n--> Digite o ano de fabricação: ");
		novoOnibus.setAnoFabricacao(input.nextInt());
		input.nextLine();

		System.out.print("\n--> Digite a quilometragem: ");
		novoOnibus.setQuilometragem(input.nextDouble());
		input.nextLine();

		listaOnibus.add(novoOnibus);

		System.out.println("\n\n==> Ônibus cadastrado com sucesso!");
		Utils.aguardarTecla();
	}

	public static void listarOnibus() {
		System.out.println("========= LISTA DE ÔNIBUS DA ROTA");

		if (listaOnibus.size() == 0) {
			System.out.println("\n--> Não existem ônibus cadastrados para esta rota.");
			Utils.aguardarTecla();
			return;
		}

		for (int i = 0; i < listaOnibus.size(); i++)
			exibirOnibus(listaOnibus.get(i), i + 1);

		Utils.aguardarTecla();
	}

	public static void alterarDadosDoOnibus(Scanner input) {
		Onibus onibus;
		int id;
		int opMenu = 0;

		if (ListaOnibus.getQuantidade() == 0) {
			System.out.println("\n========= ALTERAR DADOS DO ÔNIBUS");
			System.out.println("\n--> Não existem ônibus cadastrados.");
			Utils.aguardarTecla();
			return;
		}

		Utils.limpaTela();

		System.out.println("\n========= ALTERAR DADOS DO ÔNIBUS");
		ListaOnibus.listarOpcoesOnibus();

		System.out.print("\n--> Digite o ID do ônibus que deseja alterar: ");
		id = input.nextInt();
		input.nextLine();

		onibus = ListaOnibus.buscarOnibus(id);

		if (onibus == null) {
			System.out.println("\n==!== AVISO: o ID informado não foi encontrado!");
			Utils.aguardarTecla();
			return;
		}

		do {
			Utils.limpaTela();

			System.out.println("\n========= ALTERAR DADOS DO ÔNIBUS");
			ListaOnibus.exibirOnibus(onibus);

			System.out.println("\n--> Qual dado deseja alterar?");
			System.out.println("(1) Alterar Marca");
			System.out.println("(2) Alterar Modelo");
			System.out.println("(3) Alterar Ano de Fabricação");
			System.out.println("(4) Alterar Quilometragem");
			System.out.println("(9) Cancelar Alterações e Voltar");

			System.out.println("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					System.out.print("\n--> Digite a nova marca: ");
					onibus.setMarca(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 2:
					System.out.print("\n--> Digite o novo modelo: ");
					onibus.setModelo(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 3:
					System.out.print("\n--> Digite o novo ano de fabricação: ");
					onibus.setAnoFabricacao(input.nextInt());
					input.nextLine();

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 4:
					System.out.print("\n--> Digite a nova quilometragem: ");
					onibus.setQuilometragem(input.nextDouble());
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

	public static void excluirOnibus(Scanner input) {
		Onibus onibus;
		int id;

		if (ListaOnibus.getQuantidade() == 0) {
			System.out.println("\n========= EXCLUIR ÔNIBUS");
			System.out.println("\n--> Não existem ônibus cadastrados.");
			Utils.aguardarTecla();
			return;
		}

		do {
			Utils.limpaTela();

			System.out.println("\n========= EXCLUIR ÔNIBUS");
			ListaOnibus.listarOnibus();

			System.out.print("\n--> Digite o ID do ônibus que deseja excluir: ");
			id = input.nextInt();
			input.nextLine();

			onibus = ListaOnibus.buscarOnibus(id);

			if (onibus == null) {
				System.out.println("\n==!== AVISO: o ID informado não foi encontrado!");
				Utils.aguardarTecla();
			}
		} while (onibus == null);

		ListaOnibus.exibirOnibus(onibus);
		listaOnibus.remove(onibus);
		System.out.println("\n\n==> Ônibus excluído com sucesso!");

		Utils.aguardarTecla();
	}
}
