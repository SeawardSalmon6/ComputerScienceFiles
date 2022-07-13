import java.util.Scanner;

public final class Inputs {
  public static void printSectionHeader(String title) {
    System.out.printf("\n================= %s\n", title);
  }

  public static String readUserString(String label, Scanner sc) {
    String str = "";

    System.out.print("\n  --> " + label);
    str = sc.nextLine();

    return str;
  }

  public static int readUserInt(String label, Scanner sc) {
    int num = 0;

    System.out.print("\n  --> " + label);
    num = sc.nextInt();
    sc.nextLine();

    return num;
  }

  public static long readUserLong(String label, Scanner sc) {
    long num = 0;

    System.out.print("\n  --> " + label);
    num = sc.nextLong();
    sc.nextLine();

    return num;
  }
}