public class Lampada {
  private boolean state = false;

  public void liga() {
    this.state = true;
  }

  public void desliga() {
    this.state = false;
  }

  public String observa() {
    return state ? "ligada" : "desligada";
  }

  public static void main(String args[]) {
    Lampada lamp1 = new Lampada();
    Lampada lamp2 = new Lampada();

    lamp1.liga();
    lamp2.desliga();

    System.out.println("A lâmpada 01 está " + lamp1.observa());
    System.out.println("A lâmpada 02 está " + lamp2.observa());
  }
}
