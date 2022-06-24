public class Aluno extends Pessoa {
  private double media;

  // =========== Métodos da Classe
  public void alterarMedia(double media) {
    if (media >= 0 && media <= 10)
      this.media = media;
  }

  public void estudarCalculo() {
    System.out.println("Eu vou reprovar, é isso, já aceitei...");
  }

  // =========== Construtores
  public Aluno() {
    this("", 0, '\0', 0, "", 0);
  }

  public Aluno(String nome, int idade, char sexo, int faltas, String estadoCivil, double media) {
    super(nome, idade, sexo, faltas, estadoCivil);
    this.alterarMedia(media);
  }

  // =========== Getters e Setters
  public double getMedia() {
    return this.media;
  }
}
