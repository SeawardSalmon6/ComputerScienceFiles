import java.util.Scanner;

public class Exercicio02
{
  public static void main(String[] args)
  {
    Scanner sc = new Scanner(System.in);
    double peso, altura, imc;

    System.out.print("Digite seu peso: ");
    peso = sc.nextDouble();

    System.out.print("Digite sua altura (em metros): ");
    altura = sc.nextDouble();

    imc = peso / (altura * altura);

    if(imc < 18.5) {
      System.out.println("Você está abaixo do peso");
    } else if(imc >= 18.5 && imc < 25) {
      System.out.println("Você está com IMC normal");
    } else if(imc >= 25 && imc < 30) {
      System.out.println("Você está com sobrepeso");
    } else {
      System.out.println("Você é obeso");
    }
  }
}