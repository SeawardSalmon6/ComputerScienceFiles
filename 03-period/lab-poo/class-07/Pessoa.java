import java.lang.Comparable;

public class Pessoa implements Comparable<Pessoa> {
  private String nome;
  private int idade;
  private double salario;

  @Override
  public int compareTo(Pessoa outraPessoa) {
    if (this.salario < outraPessoa.salario)
      return -1;

    if (this.salario > outraPessoa.salario)
      return 1;

    return 0;
  }

  public Pessoa() {
    this("", 0, 0.0);
  }

  public Pessoa(String nome, int idade, double salario) {
    this.setNome(nome);
    this.setIdade(idade);
    this.setSalario(salario);
  }

  public String getNome() {
    return this.nome;
  }

  public int getIdade() {
    return this.idade;
  }

  public double getSalario() {
    return this.salario;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setIdade(int idade) {
    this.idade = idade;
  }

  public void setSalario(double salario) {
    this.salario = salario;
  }

}
