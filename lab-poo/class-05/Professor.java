public class Professor extends Pessoa {
  private double salario;
  private String departamento;

  // =========== Métodos da Classe
  public void aumentarSalario(double salario) {
    if (salario > this.salario)
      this.salario = salario;
  }

  public void corrigirProvas() {
    System.out.println("MEU DEUS DO CÉU, só aluno burro aqui!");
  }

  // =========== Construtores
  public Professor() {
    this("", 0, '\0', 0, "", 0, "");
  }

  public Professor(String nome, int idade, char sexo, int faltas, String estadoCivil, double salario,
      String departamento) {
    super(nome, idade, sexo, faltas, estadoCivil);
    this.aumentarSalario(salario);
    this.setDepartamento(departamento);
  }

  // =========== Getters e Setters
  public double getSalario() {
    return this.salario;
  }

  public String getDepartamento() {
    return this.departamento;
  }

  public void setDepartamento(String departamento) {
    this.departamento = departamento;
  }
}
