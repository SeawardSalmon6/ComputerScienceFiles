#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv) {
	int myRank, size, msgItem;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

	if(myRank == 0) {
		msgItem = 42;
		MPI_Send(&msgItem, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
		printf("Proc %d: Message Sent: %d\n", myRank, msgItem);
		fflush(stdout);
	} else if(myRank == 1) {
		MPI_Recv(&msgItem, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		printf("Proc %d: Message Received: %d\n", myRank, msgItem);
		fflush(stdout);
	}

	MPI_Finalize();
	return 0;
}