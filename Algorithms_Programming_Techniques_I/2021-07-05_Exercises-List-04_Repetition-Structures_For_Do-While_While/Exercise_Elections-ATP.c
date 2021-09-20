#include <stdio.h>
#include <ctype.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "Portuguese");

	int voto = 0;
	int candidato1 = 0,
		candidato2 = 0,
		candidato3 = 0,
		candidato4 = 0,
		nulos = 0,
		brancos = 0;
	double qtdVotos = 0;

	char resp;

	do {
		printf("\nEleitor %.0lf -- Insira seu voto: ", qtdVotos + 1);
		scanf(" %d", &voto);

		switch(voto) {
			case 1:
				candidato1++;
				break;
			case 2:
				candidato2++;
				break;
			case 3:
				candidato3++;
				break;
			case 4:
				candidato4++;
				break;
			case 5:
				nulos++;
				break;
			case 6:
				brancos++;
				break;
			case 0:
			    break;
			default:
				printf("\nVoto inválido!\n");
				break;
		}

        if(voto >= 1 && voto <= 6)
		    qtdVotos++;

		printf("\n------------------------------");

	} while(voto != 0);

	double porcentagem = (brancos + nulos) / qtdVotos;

	printf("\n========= RESULTADOS =========\n");
	printf("\nTotal de Votos Válidos: %.0lf voto(s) válido(s)", qtdVotos);
    printf("\n   - Candidato 1:      %d voto(s)", candidato1);
    printf("\n   - Candidato 2:      %d voto(s)", candidato2);
    printf("\n   - Candidato 3:      %d voto(s)", candidato3);
    printf("\n   - Candidato 4:      %d voto(s)", candidato4);
	printf("\n   - Votos Brancos:    %d voto(s) branco(s)", brancos);
	printf("\n   - Votos Nulos:      %d voto(s) nulos(s)", nulos);
	printf("\n\n==> Porcentagem de Votos Nulos e Brancos: %.2lf%%\n\n", porcentagem * 100);

	return 0;
}