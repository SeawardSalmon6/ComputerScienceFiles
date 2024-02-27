#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
	int size, myRank;
	int valorInicial, valorModificado, total, nproc;
	MPI_Status st;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	printf("Hello! Sou o processo %d de um total de %d\n", myRank, size);
	fflush(stdout);

	if(myRank == 0) {
		for(nproc = 1; nproc < size; nproc++) {
			valorInicial = nproc * 10;
			MPI_Send(&valorInicial, 1, MPI_INT, nproc, 0, MPI_COMM_WORLD);
			printf("MESTRE - Enviei %d para PROC(%d)\n", valorInicial, nproc);
			fflush(stdout);
		}

		total = 0;
		for(nproc = 1; nproc < size; nproc++) {
			MPI_Recv(&valorModificado, 1, MPI_INT, MPI_ANY_SOURCE, 1, MPI_COMM_WORLD, &st);
			printf("MESTRE - Recebi o valor MODIFICADO %d\n", valorModificado);
			fflush(stdout);

			total += valorModificado;
		}

		printf("MESTRE - Total do Processamento = %d\n", total);
		fflush(stdout);

	} else {
		MPI_Recv(&valorInicial, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &st);
		printf("ESCRAVO(%d) - Recebi %d do mestre\n", myRank, valorInicial);
		fflush(stdout);

		valorModificado = valorInicial * 10;
		MPI_Send(&valorModificado, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
		printf("ESCRAVO(%d) - Valor MODIFICADO = %d\n", myRank, valorModificado);
	}

	MPI_Finalize();

	return 0;
}