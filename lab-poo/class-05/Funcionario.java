public class Funcionario extends Pessoa {
  private double salario;
  private boolean insalubridade;

  // =========== Métodos da Classe
  public void aumentarSalario(double salario) {
    if (salario > this.salario)
      this.salario = salario;
  }

  public void alterarInsalubridade(boolean insalubridade) {
    this.insalubridade = insalubridade;
  }

  public void pedirAumento() {
    System.out.println("Quero aumento de salário, por favor.");
  }

  // =========== Construtores
  public Funcionario() {
    this("", 0, '\0', 0, "", 0, false);
  }

  public Funcionario(String nome, int idade, char sexo, int faltas, String estadoCivil, double salario,
      boolean insalubridade) {
    super(nome, idade, sexo, faltas, estadoCivil);
    this.aumentarSalario(salario);
    this.alterarInsalubridade(insalubridade);
  }

  // =========== Getters e Setters
  public double getSalario() {
    return this.salario;
  }

  public boolean temInsalubridade() {
    return insalubridade;
  }
}
