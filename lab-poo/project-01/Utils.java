public class Utils {
	private static boolean habilitado = true;

	public static void setAguardar(boolean habilitado) {
		Utils.habilitado = habilitado;
	}

	// Limpa Tela, como se fosse o system("clear")
	public static void limpaTela() {
		final String ANSI_CODE_CLEANER = "\033[H\033[2J";
		System.out.print(ANSI_CODE_CLEANER);
		System.out.flush();
	}

	// Tipo um system("pause")
	public static void aguardarTecla() {
		if (habilitado) {
			System.out.println("\n\nPressione uma tecla para continuar...");
			try {
				System.in.read();
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
	}
}