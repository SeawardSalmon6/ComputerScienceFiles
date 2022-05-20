import java.util.Scanner;

public class Exercicio03
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    double a, b, c, delta, r1, r2;

    System.out.print("Digite o valor de A: ");
    a = sc.nextDouble();

    if(a == 0) {
      System.out.print("A expressão não é de segundo grau");
      System.exit(1);
    }

    System.out.print("Digite o valor de B: ");
    b = sc.nextDouble();

    System.out.print("Digite o valor de C: ");
    c = sc.nextDouble();

    delta = (b * b) - 4 * a * c;
  
    if(delta < 0) {
      System.out.println("A equação não possui raízes no campo dos reais");
    } else if(delta == 0) {
      r1 = -b / (a * 2);
      System.out.println("A equação possui somente uma raiz e r1 vale: " + r1);
    } else {
      r1 = (-b + Math.sqrt(delta)) / (a * 2);
      r2 = (-b - Math.sqrt(delta)) / (a * 2);
      System.out.println("A raízes da equação são r1 = " + r1 + " e r2 = " + r2);
    }
  }
}