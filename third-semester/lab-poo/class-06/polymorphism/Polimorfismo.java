public class Polimorfismo {
  public static void main(String[] args) {
    Veiculo v = new Veiculo(1995, 3, "Triciclo", "ABC-1234");
    Carro onix = new Carro(2014, 4, "Onix", "XYZ-9876", "José", 2019);
    Onibus cometa = new Onibus(2021, 4, "Cometa", "PTZ-5478", 44);

    System.out.println("Veículo: " + calculaPedagio(v));
    System.out.println("Carro: " + calculaPedagio(onix));
    System.out.println("Ônibus: " + calculaPedagio(cometa));
  }

  public static double calculaPedagio(Veiculo v) {
    double pedagio;

    if (v instanceof Carro)
      pedagio = 1.5 * v.getQuantPneus();
    else if (v instanceof Onibus)
      pedagio = 3.0 * v.getQuantPneus();
    else
      pedagio = 11.87;

    return pedagio;
  }
}
