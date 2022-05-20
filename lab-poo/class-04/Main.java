public class Main {
  public static void main(String[] args) {
    Turma alunos = new Turma("COMPUTARIA");
    Aluno novoAluno;

    if (Turma.mostrarMenu() == 1) {
      novoAluno = alunos.novoAluno();
      alunos.exibeAluno(novoAluno);
      alunos.removerAluno(novoAluno);
      alunos.exibeAluno(novoAluno);
    }
  }
}
