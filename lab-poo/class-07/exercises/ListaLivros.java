import java.util.Map;
import java.util.HashMap;

public class ListaLivros {
  private static Map<String, Livro> livros = new HashMap<>();

  // ======= Métodos da Classe
  public static Livro buscaLivro(String isbn) {
    return livros.get(isbn);
  }

  public static void adicionarLivro(Livro novoLivro) {
    livros.put(novoLivro.getIsbn(), novoLivro);
  }
}
