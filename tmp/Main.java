import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int i = 0;

    Backup.buscarDados("pessoas.txt");

    // do {
    // Pessoa novaPessoa = new Pessoa();

    // Inputs.printSectionHeader("Adicionar Nova Pessoa");
    // novaPessoa.setNome(Inputs.readUserString("Insira o nome do usuário: ", sc));
    // novaPessoa.setIdade(Inputs.readUserInt("Insira a idade do usuário: ", sc));

    // ListaPessoas.adicionarPessoa(novaPessoa);

    // i++;
    // } while (i != 4);

    for (i = 0; i < ListaPessoas.getQuantidade(); i++) {
      Inputs.printSectionHeader("Pessoa " + i);
      System.out.println(ListaPessoas.getPessoa(i).getNome());
      System.out.println(ListaPessoas.getPessoa(i).getIdade());
    }

    Backup.salvarDados("pessoas.txt", ListaPessoas.getLista());

    sc.close();
  }
}