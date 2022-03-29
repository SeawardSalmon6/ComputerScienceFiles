#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv) {
	int nproc, size, myRank;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	for(nproc = 0; nproc < size; nproc++) {
		if(nproc == myRank) {
			printf("Hello from processor %d of %d\n", myRank, size);
			fflush(stdout);
		}
		MPI_Barrier(MPI_COMM_WORLD);
	}

	MPI_Finalize();

	return 0;
}