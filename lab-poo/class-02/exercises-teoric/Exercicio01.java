import java.util.Scanner;

public class Exercicio01
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int n1, quadrado, cubo;

    System.out.print("Digite n1: ");
    n1 = sc.nextInt();

    quadrado = n1 * n1;
    cubo = quadrado * n1;

    System.out.println("O quadrado é " + quadrado);
    System.out.println("O cubo é " + cubo);
  }
}