import java.util.Scanner;

public class Exercicio04
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int num;

    System.out.print("Digite um número: ");
    num = sc.nextInt();

    if(num == 0) {
      System.out.println("Não podemos realizar divisões por zero. Insira um valor válido");
      System.exit(1);
    }

    for(int i = 1; i <= 100; i++) {
      if(i % num == 0) {
        System.out.println(i);
      }
    }
  }
}