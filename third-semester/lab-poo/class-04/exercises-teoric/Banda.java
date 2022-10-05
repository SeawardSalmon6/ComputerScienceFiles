public class Banda {
  private String nome;
  private String genero;
  private int qtdMembros;
  private int anoPrimeiroAlbum;

  public Banda() {
    this("", "", 0, 0);
  }

  public Banda(String nome, String genero) {
    this.setNome(nome);
    this.setGenero(genero);
  }

  public Banda(String nome, String genero, int qtdMembros, int anoPrimeiroAlbum) {
    this.setNome(nome);
    this.setGenero(genero);
    this.setQtdMembros(qtdMembros);
    this.setAnoPrimeiroAlbum(anoPrimeiroAlbum);
  }

  public String getNome() {
    return nome;
  }

  public int getAnoPrimeiroAlbum() {
    return anoPrimeiroAlbum;
  }

  public int getQtdMembros() {
    return qtdMembros;
  }

  public String getGenero() {
    return genero;
  }

  public void setAnoPrimeiroAlbum(int anoPrimeiroAlbum) {
    if (anoPrimeiroAlbum > 0) {
      this.anoPrimeiroAlbum = anoPrimeiroAlbum;
    } else {
      System.out.println("Insira um valor válido!");
    }
  }

  public void setQtdMembros(int qtdMembros) {
    if (qtdMembros > 0) {
      this.qtdMembros = qtdMembros;
    } else {
      System.out.println("Insira um valor válido!");
    }
  }

  public void setGenero(String genero) {
    this.genero = genero;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }
}
