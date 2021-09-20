#include <stdio.h>
#include <string.h>

int main() {
	// Statement 1: the wolf can't be alone with the goat
	// Statement 2: the goat can't be alone with the alfafa

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  Man\n  Wolf\n  Goat\n  Alfafa\n");
	
	// First Step: the sailor takes the goat and leaves in the right riverside

	printf("\nFirst Move: Man and Goat\n");

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  Wolf\t\t\t\t\t\tMan\n  Alfafa\t\t\t\t\tGoat\n");

	// Second Step: the sailor go alone to the left riverside

	printf("\nSecond Move: Man alone\n");

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  Man\n  Wolf\n  Alfafa\t\t\t\t\tGoat\n");

	// Third Step: the sailor takes the wolf and leaves it on the right riverside

	printf("\nThird Move: Man and Wolf\n");

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  \t\t\t\t\t\tWolf\n \t\t\t\t\t\tMan\n  Alfafa\t\t\t\t\tGoat\n");

	// Fourt Step: the sailor takes the goat and leaves it on the left riverside

	printf("\nFourth Move: Man and Goat\n");

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  Man\t\t\t\t\t\tWolf\n  Goat\n  Alfafa\n");

	// Fifth Step: the sailor takes the alfafa and leaves it on the right riverside

	printf("\nFifth Move: Man and Alfafa\n");

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  Goat\t\t\t\t\t\tWolf\n  \t\t\t\t\t\tMan\n  \t\t\t\t\t\tAlfafa\n");

	// Sixth Step: the sailor returns alone to right riverside

	printf("\nSixth Move: Man alone\n");

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  Man\t\t\t\t\t\tWolf\n  Goat\t\t\t\t\t\tAlfafa\n");

	// Last Step: the sailor go with the goat to right riverside, ending the crossing

	printf("\nLast Move: Man and Goat\n");

	printf("\n\t========== A Travessia do Rio ==========");
	printf("\n| Margem Esquerda"); printf("\t\t\t\tMargem Direita|\n");
	printf("\n  \t\t\t\t\t\tMan\n  \t\t\t\t\t\tWolf\n  \t\t\t\t\t\tGoat\n  \t\t\t\t\t\tAlfafa\n");

	printf("\n\t========== Fim da Travessia ==========\n\n");

	return 0;
}