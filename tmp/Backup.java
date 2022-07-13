import java.util.List;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public final class Backup {
  private static final String caminho = "./files/";

  public static void salvarDados(String nomeArquivo, List<Pessoa> listaDados) {
    try {
      File arq = new File(caminho + nomeArquivo);
      FileWriter wr = new FileWriter(arq);

      int i = 0;
      while (i != listaDados.size()) {
        wr.write(listaDados.get(i).getNome() + ";");
        wr.write(listaDados.get(i).getIdade() + ";");
        wr.write("\n");

        i++;
      }

      wr.close();
    } catch (IOException e) {
      System.out.println("Erro: " + e);
    }
  }

  public static void buscarDados(String nomeArquivo) {
    try {
      FileReader arq = new FileReader(caminho + nomeArquivo);
      BufferedReader reader = new BufferedReader(arq);
      String[] dadosLinha;

      while (reader.ready()) {
        Pessoa novaPessoa = new Pessoa();
        dadosLinha = reader.readLine().split(";");

        novaPessoa.setNome(dadosLinha[0]);
        novaPessoa.setIdade(Integer.parseInt(dadosLinha[1]));

        ListaPessoas.adicionarPessoa(novaPessoa);
      }

      reader.close();
    } catch (IOException e) {
      System.out.println("Erro: " + e);
    }
  }
}
