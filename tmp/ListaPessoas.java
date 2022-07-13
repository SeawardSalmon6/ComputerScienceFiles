import java.util.ArrayList;
import java.util.List;

public final class ListaPessoas {
  private static List<Pessoa> listaPessoas = new ArrayList<>();

  public static void adicionarPessoa(Pessoa novaPessoa) {
    if (novaPessoa != null) {
      listaPessoas.add(novaPessoa);
    }
  }

  public static Pessoa getPessoa(int i) {
    return listaPessoas.get(i);
  }

  public static List<Pessoa> getLista() {
    return listaPessoas;
  }

  public static int getQuantidade() {
    return listaPessoas.size();
  }
}
