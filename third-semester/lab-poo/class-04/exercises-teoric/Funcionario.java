public class Funcionario {
  private String nome;
  private String matricula;
  private String cargo;
  private int idade;

  public Funcionario() {
    this("", "", "", 0);
  }

  public Funcionario(String nome, String matricula) {
    this.setNome(nome);
    this.setMatricula(matricula);
  }

  public Funcionario(String nome, String matricula, String cargo, int idade) {
    this.setNome(nome);
    this.setMatricula(matricula);
    this.setCargo(cargo);
    this.setIdade(idade);
  }

  public String getNome() {
    return nome;
  }

  public String getMatricula() {
    return matricula;
  }

  public String getCargo() {
    return cargo;
  }

  public int getIdade() {
    return idade;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setMatricula(String matricula) {
    this.matricula = matricula;
  }

  public void setCargo(String cargo) {
    this.cargo = cargo;
  }

  public void setIdade(int idade) {
    if (idade > 0) {
      this.idade = idade;
    } else {
      System.out.println("Insira um valor válido!");
    }
  }

}