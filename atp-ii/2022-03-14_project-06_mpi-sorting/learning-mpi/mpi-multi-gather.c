#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char** argv) {
	int myRank, worldSize, i, j;
	int vetor[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	MPI_Init(NULL, NULL);
	MPI_Comm_size(MPI_COMM_WORLD, &worldSize);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	int *recvBuf = (int*) malloc(sizeof(int) * 5);
	MPI_Scatter(vetor, 2, MPI_INT, recvBuf, 2, MPI_INT, 0, MPI_COMM_WORLD);

	for(j = 0; j < worldSize; j++) {
		if(myRank == j) {
			for(i = 0; i < 10; i++) {
				printf("[%d]", recvBuf[i]);
				fflush(stdout);
			}
			printf("\n");
			fflush(stdout);
		}
	}

	MPI_Barrier(MPI_COMM_WORLD);

	MPI_Finalize();
	return 0;
}