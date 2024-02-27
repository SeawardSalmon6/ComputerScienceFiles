import java.util.Scanner;

public class Menus {
	private static boolean acessoAdm = false;

	public static void menuPrincipal(Scanner input) {
		int opMenu;

		do {
			Utils.limpaTela();

			System.out.println("\n--> Bem-vindo(a) a Viação Asteróide!");

			System.out.println("\n========= MENU PRINCIPAL");
			System.out.println("(1) Comprar Passagem");
			System.out.println("(2) Cancelar Passagem");
			System.out.println("(3) Alterar Meus Dados");
			System.out.println("(4) Minhas Passagens");
			System.out.println("(5) Acessar ADM");
			System.out.println("(9) Sair");

			System.out.print("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					Utils.limpaTela();
					ListaPassageiros.comprarPassagem(input);
					break;
				case 2:
					Utils.limpaTela();
					ListaPassageiros.cancelarPassagem(input);
					break;
				case 3:
					Utils.limpaTela();
					ListaPassageiros.alterarMeusDados(input);
					break;
				case 4:
					Utils.limpaTela();
					ListaPassageiros.minhasPassagens(input);
					break;
				case 5:
					Utils.limpaTela();

					if (Menus.verificarAcesso(input)) {
						Utils.limpaTela();
						Menus.acessarAdm(input);
					}

					break;
				case 9:
					Utils.limpaTela();
					System.out.println("---> Obrigado por utilizar nossa aplicação!\n");
					break;
				case 0: // Desabilita os awaits (pauses)
					Utils.setAguardar(false);
					break;
				case -1: // Habilita os awaits (pauses)
					Utils.setAguardar(true);
					break;
				default:
					System.out.println("\n==!== AVISO: Insira uma opção válida!");
					Utils.aguardarTecla();
					break;
			}
		} while (opMenu != 9);
	}

	// ========================================== ADMINISTRAÇÃO
	public static boolean verificarAcesso(Scanner input) {
		final String SENHA_ADMIN = "eh_trivial";
		String senhaLida;

		System.out.println("\n========= ADMINISTRAÇÃO");

		System.out.print("\n--> Digite a senha: ");
		senhaLida = input.nextLine();

		if (!senhaLida.equals(SENHA_ADMIN)) {
			System.out.println("\n---> Senha inválida!");
			Utils.aguardarTecla();
			return false;
		}

		Menus.acessoAdm = true;
		return true;
	}

	public static void acessarAdm(Scanner input) {
		if (!Menus.acessoAdm) {
			Menus.acessoAdm = false;
			return;
		}

		int opMenu;

		do {
			Utils.limpaTela();

			System.out.println("\n========= ADMINISTRAÇÃO");
			System.out.println("(1) Gerenciar Ônibus");
			System.out.println("(2) Gerenciar Motoristas");
			System.out.println("(3) Gerenciar Rotas");
			System.out.println("(9) Voltar Para o Menu Principal");

			System.out.print("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					Utils.limpaTela();
					Menus.gerenciarOnibus(input);
					break;
				case 2:
					Utils.limpaTela();
					Menus.gerenciarMotorista(input);
					break;
				case 3:
					Utils.limpaTela();
					Menus.gerenciarRotas(input);
					break;
				case 9:
					Menus.acessoAdm = false;
					break;
				default:
					System.out.println("\n==!== AVISO: Insira uma opção válida!");
					Utils.aguardarTecla();
					break;
			}
		} while (opMenu != 9);
	}

	public static void gerenciarOnibus(Scanner input) {
		int opMenu;

		do {
			Utils.limpaTela();

			System.out.println("\n========= GERENCIAR ÔNIBUS");
			System.out.println("(1) Cadastrar Ônibus");
			System.out.println("(2) Alterar Dados dos Ônibus");
			System.out.println("(3) Remover Ônibus");
			System.out.println("(4) Listar os Ônibus");
			System.out.println("(9) Voltar Para Administração");

			System.out.print("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					Utils.limpaTela();
					ListaOnibus.cadastrarOnibus(input);
					break;
				case 2:
					Utils.limpaTela();
					ListaOnibus.alterarDadosDoOnibus(input);
					break;
				case 3:
					Utils.limpaTela();
					ListaOnibus.excluirOnibus(input);
					break;
				case 4:
					Utils.limpaTela();
					ListaOnibus.listarOnibus();
					break;
				case 9:
					break;
				default:
					System.out.println("\n==!== AVISO: Insira uma opção válida!");
					Utils.aguardarTecla();
					break;
			}
		} while (opMenu != 9);
	}

	public static void gerenciarMotorista(Scanner input) {
		int opMenu;

		do {
			Utils.limpaTela();

			System.out.println("\n========= GERENCIAR MOTORISTAS");
			System.out.println("(1) Cadastrar Motoristas");
			System.out.println("(2) Alterar Dados dos Motoristas");
			System.out.println("(3) Remover Motoristas");
			System.out.println("(4) Listar os Motoristas");
			System.out.println("(9) Voltar Para Administração");

			System.out.print("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					Utils.limpaTela();
					ListaMotoristas.cadastrarMotorista(input);
					break;
				case 2:
					Utils.limpaTela();
					ListaMotoristas.alterarMotorista(input);
					break;
				case 3:
					Utils.limpaTela();
					ListaMotoristas.excluirMotorista(input);
					break;
				case 4:
					Utils.limpaTela();
					ListaMotoristas.listarMotoristas();
					break;
				case 9:
					break;
				default:
					System.out.println("\n==!== AVISO: Insira uma opção válida!");
					Utils.aguardarTecla();
					break;
			}

		} while (opMenu != 9);
	}

	public static void gerenciarRotas(Scanner input) {
		int opMenu;

		do {
			Utils.limpaTela();

			System.out.println("\n========= GERENCIAR ROTAS");
			System.out.println("(1) Cadastrar Rota");
			System.out.println("(2) Alterar Dados de uma Rota");
			System.out.println("(3) Excluir Rota");
			System.out.println("(4) Listar as Rotas");
			System.out.println("(9) Voltar Para Administração");

			System.out.print("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					Utils.limpaTela();
					ListaRotas.cadastrarRota(input);
					break;
				case 2:
					Utils.limpaTela();
					ListaOnibus.alterarDadosDoOnibus(input);
					break;
				case 3:
					Utils.limpaTela();
					ListaOnibus.excluirOnibus(input);
					break;
				case 4:
					Utils.limpaTela();
					ListaRotas.listarRotas();
					break;
				case 9:
					break;
				default:
					System.out.println("\n==!== AVISO: Insira uma opção válida!");
					Utils.aguardarTecla();
					break;
			}
		} while (opMenu != 9);
	}
}