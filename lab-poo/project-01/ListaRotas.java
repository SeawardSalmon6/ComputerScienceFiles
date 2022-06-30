import java.util.ArrayList;
import java.util.Scanner;

public class ListaRotas {
	private static ArrayList<Rota> listaRotas = new ArrayList<>();

	// ================ Métodos Auxiliares
	public static int getQuantidade() {
		return listaRotas.size();
	}

	public static void exibirRota(Rota rota, int index) {
		System.out.println("\n---> Rota " + String.format("%02d", index));
		System.out.println("\t- Cidade Origem: " + rota.getOrigem());
		System.out.println("\t====> Horário de Saída: " + rota.gerarSaida());
		System.out.println("\n\t- Cidade Escala (Parada): " + rota.getParada());
		System.out.println("\n\t- Cidade Destino: " + rota.getDestino());
		System.out.println("\t====> Horário de Chegada: " + rota.gerarChegada());
		System.out.println("\n- Disponibilidade: " + (rota.getRotaDisponivel() ? "DISPONÍVEL" : "INDISPONÍVEL"));
		System.out.println("---------------------------------------");
	}

	public static void exibirOpcaoRota(Rota rota, int index) {
		if (index > 0)
			System.out.println("\n| *** Opção [" + String.format("%02d", index) + "]");
		else
			System.out.println("\n| *** Opção [" + rota.getIdRota() + "]");

		System.out.println("|\t- Cidade Origem: " + rota.getOrigem());
		System.out.println("|\t====> Horário de Saída: " + rota.gerarSaida());
		System.out.println("\n|\t- Cidade Escala (Parada): " + rota.getParada());
		System.out.println("\n|\t- Cidade Destino: " + rota.getDestino());
		System.out.println("|\t====> Horário de Chegada: " + rota.gerarChegada());
		System.out.println("\n|\t- Valor da Passagem: R$" + rota.getValor());
		System.out.println("---------------------------------------");
	}

	public static void listarOpcoesRotas() {
		System.out.println("\n=========> Rotas Disponíveis");

		if (listaRotas.size() == 0) {
			System.out.println("\n--> Não existem rotas disponíveis para origem e destino informadas.");
			Utils.aguardarTecla();
			return;
		}

		for (int i = 0; i < listaRotas.size(); i++)
			exibirOpcaoRota(listaRotas.get(i), 0);
	}

	public static void listarOpcoesRotas(ArrayList<Rota> rotasDisponiveis) {
		System.out.println("\n=========> Rotas Encontradas");

		if (listaRotas.size() == 0) {
			System.out.println("\n--> Não existem rotas disponíveis para origem e destino informadas.");
			Utils.aguardarTecla();
			return;
		}

		for (int i = 0; i < rotasDisponiveis.size(); i++)
			exibirOpcaoRota(rotasDisponiveis.get(i), i + 1);
	}

	public static ArrayList<Rota> buscarRotas(String origem, String destino) {
		Rota tempRota;
		ArrayList<Rota> rotasDisponiveis = new ArrayList<>();

		if (ListaRotas.getQuantidade() == 0) {
			System.out.println("\n--> Não existem viagens disponíveis para este origem e destino.");
			Utils.aguardarTecla();
			return null;
		}

		for (int i = 0; i < listaRotas.size(); i++) {
			tempRota = listaRotas.get(i);
			if (tempRota.getOrigem().equalsIgnoreCase(origem) && tempRota.getDestino().equalsIgnoreCase(destino)
					&& tempRota.getRotaDisponivel())
				rotasDisponiveis.add(tempRota);
		}

		if (rotasDisponiveis.size() > 0) {
			return rotasDisponiveis;
		}

		return null;
	}

	public static Rota buscarRota(int id) {
		if (listaRotas.size() == 0) {
			System.out.println("\n--> Não existem ônibus cadastrados.");
			Utils.aguardarTecla();
			return null;
		}

		for (int i = 0; i < listaRotas.size(); i++) {
			if (listaRotas.get(i).getIdRota() == id) {
				return listaRotas.get(i);
			}
		}

		return null;
	}

	// ================ Métodos da Classe
	public static void cadastrarRota(Scanner input) {
		Rota tempRota = new Rota();
		Hora horaSaida = new Hora();
		Hora horaChegada = new Hora();

		System.out.println("\n========= CADASTRAR NOVA ROTA");

		System.out.print("\n--> Digite a cidade de origem: ");
		tempRota.setOrigem(input.nextLine());

		System.out.println("\n---- Horário de Saída");
		System.out.print("\t--> Horas: ");
		horaSaida.setHoras(input.nextInt());
		input.nextLine();

		System.out.print("\t--> Minutos: ");
		horaSaida.setMinutos(input.nextInt());
		input.nextLine();

		tempRota.setSaida(horaSaida);

		System.out.print("\n--> Digite a cidade onde será feita a escala (parada): ");
		tempRota.setParada(input.nextLine());

		System.out.print("\n--> Digite a cidade de destino: ");
		tempRota.setDestino(input.nextLine());

		System.out.println("\n---- Horário de Chegada");
		System.out.print("\t--> Horas: ");
		horaChegada.setHoras(input.nextInt());
		input.nextLine();

		System.out.print("\t--> Minutos: ");
		horaChegada.setMinutos(input.nextInt());
		input.nextLine();

		System.out.print("\n--> Digite o valor da passagem: ");
		tempRota.setValor(input.nextDouble());
		input.nextLine();

		tempRota.setChegada(horaChegada);

		if (ListaMotoristas.getQuantidade() > 0) {
			char resp = 'n';

			System.out.print("\n--> Deseja atribuir um motorista a esta rota (s/n)? ");
			resp = input.next().charAt(0);
			input.nextLine();

			if (Character.toLowerCase(resp) == 's') {
				int id;
				Motorista motorista = null;
				ListaMotoristas.listarOpcoesMotoristas();

				do {
					System.out.print("\n--> Insira a opção de motorista correspondente para atribuição: ");
					id = input.nextInt();
					input.nextLine();

					motorista = ListaMotoristas.buscarMotorista(id);

					if (motorista == null)
						System.out.println("\n==!== AVISO: Insira uma opção válida!\n");
					else
						tempRota.atribuirMotorista(motorista);
				} while (motorista == null);
			} else {
				tempRota.setRotaDisponivel(false);
				System.out
						.println("\n\nOBS: esta rota ficará desabilitada enquanto não houver um motorista associado.");
			}
		} else {
			tempRota.setRotaDisponivel(false);
			System.out.println("\n\nOBS: esta rota ficará desabilitada enquanto não houver um motorista associado.");
		}

		if (ListaOnibus.getQuantidade() > 0) {
			char resp = 'n';

			System.out.print("\n--> Deseja atribuir um ônibus a esta rota (s/n)? ");
			resp = input.next().charAt(0);
			input.nextLine();

			if (Character.toLowerCase(resp) == 's') {
				int id;
				Onibus onibus = null;
				ListaOnibus.listarOpcoesOnibus();

				do {
					System.out.print("\n--> Insira a opção de ônibus correspondente para atribuição: ");
					id = input.nextInt();
					input.nextLine();

					onibus = ListaOnibus.buscarOnibus(id);

					if (onibus == null)
						System.out.println("\n==!== AVISO: Insira uma opção válida!\n");
					else
						tempRota.atribuirOnibus(onibus);
				} while (onibus == null);
			} else {
				tempRota.setRotaDisponivel(false);
				System.out.println("\n\nOBS: esta rota ficará desabilitada enquanto não houver um ônibus associado.");
			}
		} else {
			tempRota.setRotaDisponivel(false);
			System.out.println("\n\nOBS: esta rota ficará desabilitada enquanto não houver um ônibus associado.");
		}

		listaRotas.add(tempRota);
		System.out.println("\n\n==> Rota cadastrada com sucesso!");

		Utils.aguardarTecla();
	}

	public static void alterarDadosDaRota(Scanner input) {
		Rota rota;
		int id;
		int opMenu = 0;

		if (ListaRotas.getQuantidade() == 0) {
			System.out.println("\n--> Não existem rotas cadastradas.");
			Utils.aguardarTecla();
			return;
		}

		do {
			Utils.limpaTela();

			System.out.println("\n========= ALTERAR DADOS DO Rota");
			ListaRotas.listarOpcoesRotas();

			System.out.print("\n--> Digite o ID da rota que deseja alterar: ");
			id = input.nextInt();
			input.nextLine();

			rota = ListaRotas.buscarRota(id);

			if (rota == null) {
				System.out.println("\n==!== AVISO: o ID informado não foi encontrado!");
				Utils.aguardarTecla();
				return;
			}

			Utils.limpaTela();

			System.out.println("\n========= ALTERAR DADOS DA ROTA");
			ListaRotas.exibirRota(rota, 0);

			System.out.println("\n--> Qual dado deseja alterar?");
			System.out.println("(1) Alterar Cidade de Origem");
			System.out.println("(2) Alterar Cidade de Parada");
			System.out.println("(3) Alterar Cidade de Destino");
			System.out.println("(4) Alterar Horário de Saída");
			System.out.println("(5) Alterar Horário de Chegada");
			System.out.println("(6) Alterar Motorista");
			System.out.println("(7) Alterar Ônibus");
			System.out.println("(9) Cancelar Alterações e Voltar");

			System.out.println("\n--> Digite a opção desejada: ");
			opMenu = input.nextInt();
			input.nextLine();

			switch (opMenu) {
				case 1:
					System.out.print("\n--> Digite a nova cidade de origem: ");
					rota.setOrigem(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 2:
					System.out.print("\n--> Digite a nova cidade de parada: ");
					rota.setParada(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 3:
					System.out.print("\n--> Digite a nova cidade de destino: ");
					rota.setDestino(input.nextLine());

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 4:
					System.out.print("\n--> Digite o novo horário de saída: ");
					System.out.print("\t--> Horas: ");
					rota.getSaida().setHoras(input.nextInt());
					input.nextLine();

					System.out.print("\t--> Minutos: ");
					rota.getSaida().setMinutos(input.nextInt());
					input.nextLine();

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 5:
					System.out.print("\n--> Digite o novo horário de chegada: ");
					System.out.print("\t--> Horas: ");
					rota.getChegada().setHoras(input.nextInt());
					input.nextLine();

					System.out.print("\t--> Minutos: ");
					rota.getChegada().setMinutos(input.nextInt());
					input.nextLine();

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 6:
					Motorista motorista;
					ListaMotoristas.listarOpcoesMotoristas();

					do {
						System.out.print("\n--> Insira a opção de motorista correspondente para atribuição: ");
						id = input.nextInt();
						input.nextLine();

						motorista = ListaMotoristas.buscarMotorista(id);

						if (motorista == null)
							System.out.println("\n==!== AVISO: Insira uma opção válida!\n");
						else
							rota.atribuirMotorista(motorista);
					} while (motorista == null);

					System.out.println("\n\n==> Dados atualizados com sucesso!");
					break;
				case 7:
					Onibus onibus;
					ListaOnibus.listarOpcoesOnibus();

					do {
						System.out.print("\n--> Insira a opção de ônibus correspondente para atribuição: ");
						id = input.nextInt();
						input.nextLine();

						onibus = ListaOnibus.buscarOnibus(id);

						if (onibus == null)
							System.out.println("\n==!== AVISO: Insira uma opção válida!\n");
						else
							rota.atribuirOnibus(onibus);
					} while (onibus == null);

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

	public static void excluirRota(Scanner input) {
		Rota rota;
		int id;

		if (ListaRotas.getQuantidade() == 0) {
			System.out.println("\n========= EXCLUIR ROTA");
			System.out.println("\n--> Não existem rotas cadastradas.");
			Utils.aguardarTecla();
			return;
		}

		do {
			Utils.limpaTela();

			System.out.println("\n========= EXCLUIR ROTA");
			ListaRotas.listarOpcoesRotas();

			System.out.print("\n--> Digite o ID da rota que deseja excluir: ");
			id = input.nextInt();
			input.nextLine();

			rota = ListaRotas.buscarRota(id);

			if (rota == null) {
				System.out.println("\n==!== AVISO: o ID informado não foi encontrado!");
				Utils.aguardarTecla();
			}
		} while (rota == null);

		ListaRotas.exibirRota(rota, 0);
		listaRotas.remove(rota);
		System.out.println("\n\n==> Rota removida com sucesso!");

		Utils.aguardarTecla();
	}

	public static void listarRotas() {
		System.out.println("========= LISTA DE ROTAS CADASTRADAS");

		if (listaRotas.size() == 0) {
			System.out.println("\n--> Não existem rotas cadastradas.");
			Utils.aguardarTecla();
			return;
		}

		for (int i = 0; i < listaRotas.size(); i++)
			exibirRota(listaRotas.get(i), i + 1);

		Utils.aguardarTecla();
	}
}
