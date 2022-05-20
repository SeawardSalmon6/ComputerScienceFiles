public class Professor {
  private String nome;
  private String matricula;
  private String cpf;
  private String telefone;
  private int idade;

  public Professor() {
    this("", "", "", "", 0);
  }

  public Professor(String nome) {
    this.setNome(nome);
  }

  public Professor(String nome, String matricula) {
    this.setNome(nome);
    this.setMatricula(matricula);
  }

  public Professor(String nome, String matricula, String cpf) {
    this.setNome(nome);
    this.setMatricula(matricula);
    this.setCpf(cpf);
  }

  public Professor(String nome, String matricula, String cpf, String telefone) {
    this.setNome(nome);
    this.setMatricula(matricula);
    this.setCpf(cpf);
    this.setTelefone(telefone);
  }

  public Professor(String nome, String matricula, String cpf, String telefone, int idade) {
    this.setNome(nome);
    this.setMatricula(matricula);
    this.setCpf(cpf);
    this.setTelefone(telefone);
    this.setIdade(idade);
  }

  public String getNome() {
    return nome;
  }

  public int getIdade() {
    return idade;
  }

  public String getTelefone() {
    return telefone;
  }

  public String getCpf() {
    return cpf;
  }

  public String getMatricula() {
    return matricula;
  }

  public void setIdade(int idade) {
    if (idade > 0) {
      this.idade = idade;
    } else {
      System.out.println("Valor atribuído é inválido!");
    }
  }

  public void setTelefone(String telefone) {
    this.telefone = telefone;
  }

  public void setCpf(String cpf) {
    this.cpf = cpf;
  }

  public void setMatricula(String matricula) {
    this.matricula = matricula;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }
}
