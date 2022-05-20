import java.util.Scanner;

public class Exercicio06
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    int i, arr1[] = new int[10], arr2[] = new int[10], arr3[] = new int[10];

    for(i = 0; i < arr1.length; i++) {
      System.out.print("Insira o valor " + (i + 1) + " do vetor 01: ");
      arr1[i] = sc.nextInt();
    }

    for(i = 0; i < arr2.length; i++) {
      System.out.print("Insira o valor " + (i + 1) + " do vetor 02: ");
      arr2[i] = sc.nextInt();
    }

    for(i = 0; i < arr3.length; i++) {
      arr3[i] = arr1[i] * arr2[i];
      System.out.println("A multiplicação de " + arr1[i] + " e " + arr2[i] + " = " + arr3[i]);
    }
  }
}