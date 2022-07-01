import java.util.ArrayList;
import java.util.Scanner;

public class ListaPassageiros {
	private static ArrayList<Passageiro> listaPassageiros = new ArrayList<>();

	// =============== Métodos da Classe
	public static int getQuantidade() {
		return listaPassageiros.size();
	}

	public static void exibirPassageiro(Passageiro passageiro) {
		System.out.println("\n---> Passageiro " + passageiro.getNome());
		System.out.println("\t- RG: " + passageiro.getRg());
		System.out.println("\t- Endereço: " + passageiro.getEndereco());
		System.out.println("\t- Data de Nascimento: " + passageiro.gerarDataNascimento());
		System.out.println("---------------------------------------");
	}

	public static boolean rgExiste(String rg) {
		if (ListaPassageiros.getQuantidade() == 0)
			return false;

		for (int i = 0; i < listaPassageiros.size(); i++) {
			if (listaPassageiros.get(i).getRg().equals(rg))
				return true;
		}

		return false;
	}

	public static Passageiro buscarPassageiro(String rg) {
		if (listaPassageiros.size() == 0) {
			System.out.println("\n--> Não existem passageiros cadastrados.");
			Utils.aguardarTecla();
			return null;
		}

		for (int i = 0; i < listaPassageiros.size(); i++) {
			if (listaPassageiros.get(i).getRg().equals(rg))
				return listaPassageiros.get(i);
		}

		return null;
	}

	// ============================ Métodos da Classe
	public static void comprarPassagem(Scanner input) {
		ArrayList<Rota> rotasDisponiveis;
		Passageiro passageiro;
		String origem, destino, rg;
		int opEscolhida;

		if (ListaRotas.getQuantidade() == 0) {
			System.out.println("\n========= COMPRAR PASSAGEM");
			System.out.println("\n--> Não existem viagens disponíveis no momento.");
			Utils.aguardarTecla();
			return;
		}

		Utils.limpaTela();

		System.out.println("\n========= COMPRAR PASSAGEM");
		System.out.print("\n--> Insira seu RG para que possamos continuar: ");
		rg = input.nextLine();

		if (!ListaPassageiros.rgExiste(rg)) {
			Utils.limpaTela();
			passageiro = ListaPassageiros.cadastrarPassageiro(input);

			System.out.println("\n========= COMPRAR PASSAGEM");
		} else {
			passageiro = ListaPassageiros.buscarPassageiro(rg);
		}

		ListaPassageiros.exibirPassageiro(passageiro);

		System.out.print("\n--> Digite sua cidade de origem: ");
		origem = input.nextLine();

		System.out.print("\n--> Digite sua cidade de destino: ");
		destino = input.nextLine();

		rotasDisponiveis = ListaRotas.buscarRotas(origem, destino);

		if (rotasDisponiveis == null) {
			System.out.println("\n--> Não existem viagens disponíveis para esta origem e destino.");
			Utils.aguardarTecla();
			return;
		}

		do {
			ListaRotas.listarOpcoesRotas(rotasDisponiveis);

			System.out.print("\n--> Escolha a passagem desejada: ");
			opEscolhida = input.nextInt();
			input.nextLine();

			if (opEscolhida < 0 || opEscolhida > rotasDisponiveis.size()) {
				System.out.println("\n==!== AVISO: Insira um valor válido!");
				Utils.aguardarTecla();
			}
		} while (opEscolhida < 0 || opEscolhida > rotasDisponiveis.size());

		ListaPassageiros.reservarAssento(passageiro, rotasDisponiveis.get(opEscolhida - 1), input);
	}

	public static Passageiro cadastrarPassageiro(Scanner input) {
		Passageiro novoPassageiro = new Passageiro();
		Data novaData = new Data();

		System.out.println("\n========= CADASTRO DE PASSAGEIRO");

		System.out.print("\n--> Digite seu nome: ");
		novoPassageiro.setNome(input.nextLine());

		System.out.print("\n--> Digite seu RG: ");
		novoPassageiro.setRg(input.nextLine());

		System.out.println("\n===> Digite a data de nascimento");
		System.out.print("\t--> Dia: ");
		novaData.setDia(input.nextInt());
		input.nextLine();

		System.out.print("\t--> Mês: ");
		novaData.setMes(input.nextInt());
		input.nextLine();

		System.out.print("\t--> Ano: ");
		novaData.setAno(input.nextInt());
		input.nextLine();

		novoPassageiro.setDataNascimento(novaData);

		System.out.print("\n--> Digite seu endereço: ");
		novoPassageiro.setEndereco(input.nextLine());

		listaPassageiros.add(novoPassageiro);
		System.out.println("\n\n==> Passageiro cadastrado com sucesso!");

		Utils.aguardarTecla();
		return novoPassageiro;
	}

	public static void reservarAssento(Passageiro passageiro, Rota rotaSelecionada, Scanner input) {
		Onibus onibus = rotaSelecionada.getOnibusDaRota();
		int assentoLinha, assentoColuna;

		if (onibus.estaCheio()) {
			System.out.println("\n--> Não temos assentos disponíveis, escolha outra rota, por favor!");
			Utils.aguardarTecla();
			return;
		}

		do {
			Utils.limpaTela();

			onibus.exibirAssentos();

			System.out.print("\n--> Digite a linha do assento escolhido: ");
			assentoLinha = input.nextInt();
			input.nextLine();

			System.out.print("\n--> Digite a coluna do assento escolhido: ");
			assentoColuna = input.nextInt();
			input.nextLine();
		} while (assentoLinha < 1 || assentoLinha > 4 || assentoColuna < 1 || assentoColuna > 4);

		onibus.atribuirAssento(assentoLinha, assentoColuna);

		Passagem novaPassagem = new Passagem(passageiro, rotaSelecionada, assentoLinha, assentoColuna);
		passageiro.atribuirPassagem(novaPassagem);

		System.out.println("\n\n--> Passagem comprada com sucesso!");
		Utils.aguardarTecla();
	}

	public static void cancelarPassagem(Scanner input) {
		Passageiro passageiro;
		Passagem passagem;
		Onibus onibus;
		String rg;
		char resp = 'n';

		if (ListaPassageiros.getQuantidade() == 0) {
			System.out.println("\n========= CANCELAR PASSAGEM");
			System.out.println("\n--> Não temos nenhum passageiro cadastrado!");
			Utils.aguardarTecla();
			return;
		}

		System.out.println("\n========= CANCELAR PASSAGEM");
		System.out.print("\n--> Insira seu RG para que possamos continuar: ");
		rg = input.nextLine();

		if (!ListaPassageiros.rgExiste(rg)) {
			System.out.println("\n--> Não encontramos nenhum passageiro com este RG!");
			Utils.aguardarTecla();
			return;
		}

		passageiro = ListaPassageiros.buscarPassageiro(rg);
		passagem = passageiro.getMinhaPassagem();

		if (passagem == null) {
			System.out.println("\n--> Não encontramos nenhuma passagem deste passageiro!");
			Utils.aguardarTecla();
			return;
		}

		do {
			passagem.exibirPassagem();

			System.out.print("\n--> Deseja mesmo cancelar a passagem (s/n)? ");
			resp = input.next().charAt(0);
			input.nextLine();
		} while (Character.toLowerCase(resp) != 'n' && Character.toLowerCase(resp) != 's');

		if (Character.toLowerCase(resp) == 's') {
			onibus = passagem.getRotaPassagem().getOnibusDaRota();

			passageiro.setMinhaPassagem(null);
			onibus.removerAssento(passagem.getAssentoLinha(), passagem.getAssentoColuna());
			System.out.println("\n\n--> Passagem excluída com sucesso!");
		}

		Utils.aguardarTecla();
	}

	public static void alterarMeusDados(Scanner input) {
		Passageiro passageiro;
		int opMenu;
		String id;

		if (ListaPassageiros.getQuantidade() == 0) {
			System.out.println("\n========= CANCELAR PASSAGEM");
			System.out.println("\n--> Não temos nenhum passageiro cadastrado!");
			Utils.aguardarTecla();
			return;
		}

		System.out.println("\n========= ALTERAR DADOS DO PASSAGEIRO");
		System.out.print("\n--> Insira seu RG para que possamos continuar: ");
		id = input.nextLine();

		passageiro = ListaPassageiros.buscarPassageiro(id);

		if (passageiro == null) {
			System.out.println("\n==!== AVISO: o ID informado não foi encontrado!");
			Utils.aguardarTecla();
			return;
		}

		do {
			Utils.limpaTela();

			System.out.println("\n========= ALTERAÇÃO DE DADOS CADASTRAIS");
			System.out.println("(1) Alterar nome");
			System.out.println("(2) Alterar data de nascimento");
			System.out.println("(3) Alterar endereco");
			System.out.println("(9) Voltar para o Menu Principal");

			System.out.println("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					System.out.print("\n--> Digite o novo nome: ");
					passageiro.setNome(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 2:
					Data novaData = passageiro.getDataNascimento();
					System.out.print("\n--> Digite a nova data de nascimento: ");
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
				case 3:
					System.out.print("\n--> Digite o novo endereco: ");
					passageiro.setEndereco(input.nextLine());

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

	public static void minhasPassagens(Scanner input) {
		Passageiro passageiro;
		Passagem passagem;
		String rg;

		if (ListaPassageiros.getQuantidade() == 0) {
			System.out.println("\n========= MINHAS PASSAGENS");
			System.out.println("\n--> Não temos nenhum passageiro cadastrado!");
			Utils.aguardarTecla();
			return;
		}

		System.out.println("\n========= MINHAS PASSAGENS");
		System.out.print("\n--> Insira seu RG para que possamos continuar: ");
		rg = input.nextLine();

		if (!ListaPassageiros.rgExiste(rg)) {
			System.out.println("\n--> Não foi possível encontrar o passageiro especificado.");
			Utils.aguardarTecla();
			return;
		}

		passageiro = ListaPassageiros.buscarPassageiro(rg);
		passagem = passageiro.getMinhaPassagem();

		if (passagem == null) {
			System.out.println("\n--> Não encontramos nenhuma passagem deste passageiro!");
			Utils.aguardarTecla();
			return;
		}

		passagem.exibirPassagem();

		Utils.aguardarTecla();
	}
}
