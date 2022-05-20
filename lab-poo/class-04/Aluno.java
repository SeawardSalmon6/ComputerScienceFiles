public class Aluno {
  private String nomeCompleto;
  private int idade;
  private String ra;
  private String telefone;
  private String cpf;

  public Aluno() {
    this("", 0, "", "", "");
  }

  public Aluno(String nomeCompleto) {
    this.setNomeCompleto(nomeCompleto);
  }

  public Aluno(String nomeCompleto, int idade) {
    this.setNomeCompleto(nomeCompleto);
    this.setIdade(idade);
  }

  public Aluno(String nomeCompleto, int idade, String ra) {
    this.setNomeCompleto(nomeCompleto);
    this.setIdade(idade);
    this.setRa(ra);
  }

  public Aluno(String nomeCompleto, int idade, String ra, String telefone) {
    this.setNomeCompleto(nomeCompleto);
    this.setIdade(idade);
    this.setRa(ra);
    this.setTelefone(telefone);
  }

  public Aluno(String nomeCompleto, int idade, String ra, String telefone, String cpf) {
    this.setNomeCompleto(nomeCompleto);
    this.setIdade(idade);
    this.setRa(ra);
    this.setTelefone(telefone);
    this.setCpf(cpf);
  }

  public String getNomeCompleto() {
    return nomeCompleto;
  }

  public String getCpf() {
    return cpf;
  }

  public int getIdade() {
    return idade;
  }

  public String getRa() {
    return ra;
  }

  public String getTelefone() {
    return telefone;
  }

  public void setNomeCompleto(String nomeCompleto) {
    this.nomeCompleto = nomeCompleto;
  }

  public void setIdade(int idade) {
    if (idade > 0) {
      this.idade = idade;
    } else {
      System.out.println("Valor atribuído é inválido!");
    }
  }

  public void setRa(String ra) {
    this.ra = ra;
  }

  public void setTelefone(String telefone) {
    this.telefone = telefone;
  }

  public void setCpf(String cpf) {
    this.cpf = cpf;
  }
}
