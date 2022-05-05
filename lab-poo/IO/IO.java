import java.util.Scanner;

public class IO {
	public static void main(String args[]) {
		double valor;

		try (Scanner sc = new Scanner(System.in)) {
			System.out.print("Digite o valor: ");
			valor = sc.nextDouble();
		}

		System.out.println("\nO valor digitado foi " + valor);
	}
}
