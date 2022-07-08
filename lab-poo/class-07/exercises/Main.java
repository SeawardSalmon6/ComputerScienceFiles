public class Main {
  public static void main(String[] args) {
    Livro livro1 = new Livro("978-6586460025", "Algoritmos de Destruição em Massa", "Cathy O'Neil",
        "Editora Rua do Sabão", 342, 2021);
    Livro livro2 = new Livro("978-6599096389", "Cabeça Fria, Coração Quente", "Tiago Costa", "Garoa Livros", 408, 2022);
    Livro livro3 = new Livro("978-8593115240", "Alternativas Sistêmicas", "Pablo Solón", "Elefante Editora", 224, 2019);

    ListaLivros.adicionarLivro(livro1);
    ListaLivros.adicionarLivro(livro2);
    ListaLivros.adicionarLivro(livro3);

    System.out.println(ListaLivros.buscaLivro(livro1.getIsbn()).getTitulo());
  }
}
