import java.util.Scanner;

public class Exercicio05
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int i;
    double media, soma = 0, array[] = new double[10];

    for(i = 0; i < array.length; i++) {
      System.out.print("Insira a nota " + (i + 1) + ": ");
      array[i] = sc.nextDouble();
      soma += array[i];
    }

    System.out.println("--- Notas maiores que 8");
    for(i = 0; i < array.length; i++) {
      if(array[i] > 8) {
        System.out.println(array[i]);
      }
    }

    System.out.println("--- Notas entre 5 e 8");
    for(i = 0; i < array.length; i++) {
      if(array[i] >= 5 && array[i] <= 8) {
        System.out.println(array[i]);
      }
    }

    System.out.println("--- Notas menores que 5");
    for(i = 0; i < array.length; i++) {
      if(array[i] < 5) {
        System.out.println(array[i]);
      }
    }

    media = soma / array.length;
    System.out.println("A média é: " + media);
  }
}