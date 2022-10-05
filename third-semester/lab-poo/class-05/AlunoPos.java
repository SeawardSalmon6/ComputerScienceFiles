public class AlunoPos extends Aluno {
  private String linhaPesquisa;

  public void definirLinhaPesquisa(String linhaPesquisa) {
    this.linhaPesquisa = linhaPesquisa;
  }

  public AlunoPos() {
    this("", 0, '\0', 0, "", 0, "");
  }

  public AlunoPos(String nome, int idade, char sexo, int faltas, String estadoCivil, double media,
      String linhaPesquisa) {
    super(nome, idade, sexo, faltas, estadoCivil, media);
    this.definirLinhaPesquisa(linhaPesquisa);
  }

  public String getLinhasPesquisa() {
    return this.linhaPesquisa;
  }
}
