public class Main {
  public static void main(String[] args) {
    Televisao samsung = new Televisao(1999.78, 0.0, "Samsung X3443", "Uma super televisão de 42 polegadas!");
    Celular m51 = new Celular(1787.98, "Samsung M51", "Celular parrudo e com bastante bateria para seus afazeres!",
        23.89);

    System.out.println("---------- " + samsung.getNome());
    System.out.println("--> Descrição: " + samsung.getDescricao());
    System.out.println("--> Preço: R$" + (samsung.getPreco() + samsung.getImposto()));

    System.out.println();

    System.out.println("---------- " + m51.getNome());
    System.out.println("--> Descrição: " + m51.getDescricao());
    System.out.println("--> Preço: R$" + m51.getPreco());
    System.out.println("--> Crédito Ativo: R$" + m51.calculaCredito());
  }
}
