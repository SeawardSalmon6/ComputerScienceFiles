public class Pessoa {
  private String nome;
  private int idade;
  private char sexo;
  private int faltas;
  private String estadoCivil;

  // =========== Métodos da Classe
  public void registrarFaltas(int faltas) {
    this.faltas = faltas;
  }

  public void atualizarEstadoCivil(String estadoCivil) {
    this.estadoCivil = estadoCivil;
  }

  // =========== Construtores
  public Pessoa() {
    this("", 0, '\0', 0, "");
  }

  public Pessoa(String nome, int idade, char sexo, int faltas, String estadoCivil) {
    this.setNome(nome);
    this.setIdade(idade);
    this.setSexo(sexo);
    this.registrarFaltas(faltas);
    this.atualizarEstadoCivil(estadoCivil);
  }

  // =========== Getters e Setters
  public String getNome() {
    return this.nome;
  }

  public int getIdade() {
    return this.idade;
  }

  public char getSexo() {
    return this.sexo;
  }

  public int getFaltas() {
    return this.faltas;
  }

  public String getEstadoCivil() {
    return this.estadoCivil;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }

  public void setSexo(char sexo) {
    this.sexo = sexo;
  }
}
