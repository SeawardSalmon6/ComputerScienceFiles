#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
	int myRank, size;
	int distroArray[4] = { 39, 72, 129, 42 };
	int scatteredData[2] = { 0 };

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	/* --> Now we  will use the Scatter operator to distribute
	   data from distroArray into the scatteredData */
	MPI_Scatter(&distroArray, 2, MPI_INT, &scatteredData, 2, MPI_INT, 0, MPI_COMM_WORLD);

	printf("Process %d: I have received: %d and %d\n", myRank, scatteredData[0], scatteredData[1]);

	MPI_Finalize();
	return 0;
}