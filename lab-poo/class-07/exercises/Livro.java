public class Livro {
  private String isbn;
  private String titulo;
  private String autor;
  private String editora;
  private int qtdPaginas;
  private int ano;

  // ======= Construtores
  public Livro() {
    this("", "", "", "", 0, 0);
  }

  public Livro(String isbn, String titulo, String autor, String editora, int qtdPaginas, int ano) {
    this.setIsbn(isbn);
    this.setTitulo(titulo);
    this.setAutor(autor);
    this.setEditora(editora);
    this.setQtdPaginas(qtdPaginas);
    this.setAno(ano);
  }

  // ======= Getters e Setters
  public String getIsbn() {
    return this.isbn;
  }

  public String getTitulo() {
    return this.titulo;
  }

  public String getAutor() {
    return this.autor;
  }

  public String getEditora() {
    return this.editora;
  }

  public int getQtdPaginas() {
    return this.qtdPaginas;
  }

  public int getAno() {
    return this.ano;
  }

  public void setIsbn(String isbn) {
    this.isbn = isbn;
  }

  public void setTitulo(String titulo) {
    this.titulo = titulo;
  }

  public void setAutor(String autor) {
    this.autor = autor;
  }

  public void setEditora(String editora) {
    this.editora = editora;
  }

  public void setQtdPaginas(int qtdPaginas) {
    this.qtdPaginas = qtdPaginas;
  }

  public void setAno(int ano) {
    this.ano = ano;
  }
}
