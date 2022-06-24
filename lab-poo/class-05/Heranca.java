public class Heranca {
  public static void main(String[] args) {
    Pessoa jose = new Pessoa("José", 24, 'M', 1, "Solteiro");
    Aluno maria = new Aluno("Maria", 19, 'F', 0, "Solteiro", 8.5);
    AlunoPos matheus = new AlunoPos("Matheus", 27, 'M', 0, "Solteiro", 9.4, "Processamento de imagens");
    Professor caioX = new Professor("Caio Dev", 18, 'M', 2, "Casado", 5, "Matemática");
    Funcionario yoshi = new Funcionario("Yoshimitsu Darmas", 18, 'M', 0, "Casado", 1200000000, true);

    System.out.println(jose.getNome());
    System.out.println(maria.getMedia());
    System.out.println(matheus.getLinhasPesquisa());
    caioX.corrigirProvas();
    yoshi.pedirAumento();
  }
}