import java.util.ArrayList;
import java.util.Scanner;

public class Turma {
  static final int MAX_ALUNOS = 40;

  private String nomeTurma;
  private ArrayList<Aluno> alunos;
  private static int qtdAlunos;

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

  public static int mostrarMenu() {
    Scanner sc = new Scanner(System.in);
    int op = 0;

    System.out.println("\n\n========= Gerenciar Alunos");
    System.out.println(" [1] - Adicionar Aluno");
    System.out.println(" [2] - Exibir Aluno");
    System.out.println(" [3] - Cancelar");

    do {
      System.out.print("\n---> Escolha uma opção: ");
      op = sc.nextInt();

      if (op < 1 || op > 3) {
        System.out.println("\n--> Aviso: insira uma opção válida!\n");
      }
    } while (op < 1 || op > 3);

    sc.close();
    return op;
  }

  public Aluno novoAluno() {
    Scanner sc = new Scanner(System.in);
    Aluno novoAluno = new Aluno();

    char resp = 'n';

    System.out.println("\n- Insira o nome do aluno: ");
    novoAluno.setNomeCompleto(sc.nextLine());

    System.out.println("\n- Insira o RA do aluno: ");
    novoAluno.setRa(sc.nextLine());

    System.out.println("\n---> Deseja inserir os dados complementares (s/n)?  ");
    resp = sc.next().charAt(0);

    if (Character.toLowerCase(resp) == 's') {
      System.out.println("\n- Insira o CPF do aluno: ");
      novoAluno.setCpf(sc.nextLine());

      System.out.println("\n- Insira o telefone do aluno: ");
      novoAluno.setTelefone(sc.nextLine());

      System.out.println("\n- Insira a idade do aluno: ");
      novoAluno.setIdade(sc.nextInt());
    }

    sc.close();
    this.adicionarAluno(novoAluno);
    return novoAluno;
  }

  public void adicionarAluno(Aluno novoAluno) {
    alunos.add(novoAluno);
  }

  public void removerAluno(Aluno aluno) {
    int posicao = this.buscarAluno(aluno);
    if (posicao >= 0) {
      alunos.remove(posicao);
    } else {
      System.out.println("\n--> Aluno não encontrado!");
    }
  }

  public void removerAluno(String nomeAluno) {
    int posicao = this.buscarAluno(nomeAluno);
    if (posicao >= 0) {
      alunos.remove(posicao);
    } else {
      System.out.println("\n--> Aluno não encontrado!");
    }
  }

  private int buscarAluno(Aluno aluno) {
    for (int i = 0; i < alunos.size(); i++) {
      if (aluno.equals(alunos.get(i))) {
        return i;
      }
    }
    return -1;
  }

  private int buscarAluno(String nomeAluno) {
    for (int i = 0; i < alunos.size(); i++) {
      if (nomeAluno.equalsIgnoreCase(alunos.get(i).getNomeCompleto())) {
        return i;
      }
    }
    return -1;
  }

  public void exibeAluno(Aluno aluno) {
    int posicao = this.buscarAluno(aluno);
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

  public void exibeAluno(String nomeAluno) {
    int posicao = this.buscarAluno(nomeAluno);
    Aluno aluno = alunos.get(posicao);

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