public class Main {
  public static void main(String[] args) {
    Arara blu = new Arara("Anodorhynchus hyacinthinus", "Arara Azul", 4);
    Gato gatoMaconha = new Gato("Felis catus", "Gato", 4);
    Cachorro doguinho = new Cachorro("Canis lupus familiaris", "Cachorro", 4);
    Peixe nemo = new Peixe("Amphiprioninae", "Peixe Palhaço", 1);

    blu.comunicar();
    gatoMaconha.comunicar();
    doguinho.movimentar();
    nemo.movimentar();

    System.out.println();

    if (blu instanceof Arara)
      System.out.println("O Blu é uma arara!");

    if (gatoMaconha instanceof Gato)
      System.out.println("O Gato Maconha é um gato!");

    if (doguinho instanceof Cachorro)
      System.out.println("O Doguinho é um cachorro!");

    if (nemo instanceof Peixe)
      System.out.println("O Nemo é um peixe!");
  }
}
