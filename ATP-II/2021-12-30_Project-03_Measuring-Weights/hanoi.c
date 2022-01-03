#include <stdio.h>
#include <stdlib.h>

void hanoi(int n, int o, int a, int d) {
	if (n == 1) /* se apenas um disco a solu¸c~ao ´e trivial */
	/*Passo 0*/ printf ("move disco %d de %d para %d\n",n,o,d);
	else {/* sen~ao adota a solu¸c~ao recursiva */
	/*Passo 1*/ hanoi(n-1, o,d,a);
	/*Passo 2*/ printf ("move disco %d de %d para %d\n",n,o,d);
	/*Passo 3*/ hanoi(n-1, a,o,d);
	}/*Passo 4*/
}

main(int argc, char *argv[]) {
	int n; // n ´e o n´umero inicial de discos na torre

	n = atoi(argv[1]); // convertido do valor na linha de comando
	hanoi(n,1,2,3); // muda n discos do poste 1 para o poste 3
	
	return 0;
}