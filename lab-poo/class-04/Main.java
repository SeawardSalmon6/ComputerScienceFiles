public class Main {
  public static void main(String[] args) {
    Turma alunos = new Turma("COMPUTARIA");
    int op;

    do {
      op = Turma.mostrarMenu();

      switch (op) {
        case 1:
          alunos.novoAluno();
          break;
        case 2:
          alunos.exibeAluno();
          break;
        case 3:
          alunos.removerAluno();
          break;
        case 4:
          System.out.println("\nObrigado por utilizar nossa aplicação.");
        default:
          break;
      }
    } while (op != 3);
  }
}
